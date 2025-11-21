"""
实验：基于正则的对白抽取与索引系统（最终完整代码 - 提高文件读取和正则匹配的健壮性）
"""

import os
import re
import pickle
from typing import List, Optional

# --- 1. Dialogue 类 ---
class Dialogue:
    

    def __init__(self, chapter_title: str, speaker_hint: str, content: str):
        # 确保 chapter_title 属性保存的是不带 .txt 的文件名
        self.chapter_title = os.path.splitext(chapter_title)[0] if chapter_title.endswith(".txt") else chapter_title
        self.speaker_hint = speaker_hint
        self.content = content

    def __repr__(self) -> str:
        """
        返回便于打印调试的字符串
        """
        # 清理说话者提示，使输出更简洁
        speaker_name = re.sub(r'[\s:：,，.、]', '', self.speaker_hint)
        # 确保 speaker_hint 不包含动词
        speaker_name = re.sub(r'(道|说|骂|禀|喝|叫|问|答|曰|复|问曰|答道|言)$', '', speaker_name)
        return f"[{self.chapter_title}] {speaker_name}：{self.content}"


# --- 2. DialogueExtractor 类 ---
class DialogueExtractor:
    def __init__(self):
        SPEAKING_VERBS = r"(?:说道|骂道|喝道|禀道|叫道|笑道|叹道|问道|答道|分付道|喝采|喝|叫|道|曰|问|答|言|唤|唤道)"
        # 模式1：说话者在前，后跟引号中的内容（允许跨行内容）
        PATTERN_QUOTED = rf"([^\n]{{1,30}}?)\s*(?:{SPEAKING_VERBS})\s*[:：]?\s*[“\"'](.*?)[”\"']"
        # 模式2：说话者在前，但不使用引号，内容截取到换行或终止符
        PATTERN_COLON = rf"([^\n]{{1,30}}?)\s*(?:{SPEAKING_VERBS})\s*[:：]([^\n。！？\r]+)"
        # 模式3：引号在前，结尾处跟随说话者（如 “……”王进道）
        PATTERN_TAIL_SPEAKER = rf"[“\"'](.*?)[”\"']\s*([^\n]{{1,30}}?(?:{SPEAKING_VERBS}))"
        self.patterns = [
            re.compile(PATTERN_QUOTED, re.DOTALL),
            re.compile(PATTERN_COLON, re.DOTALL),
            re.compile(PATTERN_TAIL_SPEAKER, re.DOTALL),
        ]

    def extract_from_text(self, chapter_title: str, text: str) -> List[Dialogue]:
        """
        输入：章节标题 + 文本内容
        输出：该章节中所有对白的 Dialogue 对象列表
        使用多模式按在文本中出现顺序提取，避免重复覆盖。
        """
        dialogues: List[Dialogue] = []
        if not text:
            return dialogues

        # 预处理：清理特殊空格
        text = text.replace('\u00A0', '').replace('\u3000', '').strip()

        # 记录已经被接受的文本区间，避免重叠重复抽取
        accepted = [False] * (len(text) + 1)

        # 按模式循环，使用 finditer 但检查不与已接受区间重叠
        for pat in self.patterns:
            for m in pat.finditer(text):
                l, r = m.start(), m.end()
                # 若匹配与已接受区间有重叠，则跳过（优先首次匹配）
                if any(accepted[max(0, l): min(len(text), r)]):
                    continue

                # 不同模式分组含义不同，按模式解析
                if pat is self.patterns[0]:
                    speaker_hint = m.group(1)
                    content = m.group(2)
                elif pat is self.patterns[1]:
                    speaker_hint = m.group(1)
                    content = m.group(2)
                else:  # PATTERN_TAIL_SPEAKER
                    content = m.group(1)
                    speaker_hint = m.group(2)

                if not speaker_hint or not content:
                    continue

                final_speaker = re.sub(r'[\s:：,，.、]', '', speaker_hint).strip()
                final_content = content.strip()

                if final_speaker and final_content:
                    dialogues.append(Dialogue(chapter_title, final_speaker, final_content))
                    # 标记已接受区间
                    for i in range(l, r):
                        accepted[i] = True

        return dialogues


# --- 3. DialogueIndex 类 ---
class DialogueIndex:
    """
    对白索引：内部保存多个 Dialogue，支持添加、搜索、保存/加载 pickle
    """

    def __init__(self):
        self.dialogues: List[Dialogue] = []

    def add_dialogues(self, dialogues: List[Dialogue]) -> None:
        """将一批对白加入索引"""
        self.dialogues.extend(dialogues)

    def search(self, keyword: str) -> List[Dialogue]:
        """
        按关键字检索对白：关键字可以出现在 chapter_title, speaker_hint 或 content 里
        """
        if not keyword:
            return []
        lk = keyword.lower()
        res: List[Dialogue] = []
        for d in self.dialogues:
            if lk in d.content.lower() or lk in d.speaker_hint.lower() or lk in d.chapter_title.lower():
                res.append(d)
        return res

    def save_pickle(self, path: str) -> None:
        """使用 pickle 将对白索引保存到磁盘"""
        try:
            with open(path, "wb") as f:
                pickle.dump(self.dialogues, f)
            print(f"✅ 索引保存成功，共 {len(self.dialogues)} 条对白保存到 {path}")
        except Exception as e:
            print(f"❌ 索引保存失败: {e}")

    def load_pickle(self, path: str) -> bool:
        """从 pickle 文件中加载对白索引，返回是否成功加载"""
        try:
            with open(path, "rb") as f:
                self.dialogues = pickle.load(f)
            print(f"✅ 索引加载成功，共 {len(self.dialogues)} 条对白从 {path} 加载")
            return True
        except Exception:
            # 文件不存在或加载失败
            return False

# --- 4. I/O helpers ---
def read_chapter_text(filepath: str) -> Optional[str]:
    """尝试多种编码读取文件（取消长度阈值，尽量返回内容）"""
    encodings = ['utf-8', 'gbk', 'gb2312', 'big5', 'latin-1']
    for enc in encodings:
        try:
            with open(filepath, 'r', encoding=enc, errors='ignore') as f:
                content = f.read()
                if content:
                    return content
        except Exception:
            continue
    print(f"  [Error] 无法使用常见编码读取: {filepath}")
    return None


def build_or_load_index(data_dir: str, pickle_path: str) -> DialogueIndex:
    """构建或加载对白索引"""
    index = DialogueIndex()
    extractor = DialogueExtractor()

    if os.path.exists(pickle_path):
        print(f"🔍 发现缓存 {pickle_path}，从中加载对白索引...")
        if index.load_pickle(pickle_path):
            return index
    
    print("🛠️ 未发现有效缓存或加载失败，开始扫描章节文件并抽取对白...")
    if not os.path.isdir(data_dir):
        print(f"⚠️ 数据目录不存在: {data_dir}")
        return index

    # 获取所有txt文件并按名称排序，保证处理顺序（可选，但更清晰）
    all_files = sorted([f for f in os.listdir(data_dir) if f.endswith(".txt")])
    for filename in all_files:
        filepath = os.path.join(data_dir, filename)
        chapter_title = os.path.splitext(filename)[0]
        text = read_chapter_text(filepath)
        if text:
            dialogues = extractor.extract_from_text(chapter_title, text)
            index.add_dialogues(dialogues)
        else:
            print(f"    -> 文件读取失败，跳过。")

    if index.dialogues:
        index.save_pickle(pickle_path)
    return index

# --- 5. 主程序 ---
def main():
    """
    主程序入口：构建/加载索引并提供命令行搜索
    """
    # 路径配置：已根据用户提供的路径进行配置
    data_dir = r"C:\Users\62685\Desktop\测试文章_水浒传(分章回)\水浒传(分章回)"
    pickle_path = "dialogues.pkl"

    index = build_or_load_index(data_dir, pickle_path)
    if not index.dialogues:
        print("索引为空，程序退出。")
        return

    print(f"索引加载完毕，共 {len(index.dialogues)} 条对白。输入 q 退出。")
    while True:
        try:
            keyword = input("请输入关键字：").strip()
        except (EOFError, KeyboardInterrupt):
            print("\n退出。")
            break
        if keyword.lower() in ("q", "quit"):
            break
        if not keyword:
            continue
        results = index.search(keyword)
        print(f"共找到 {len(results)} 条结果，显示前15条：")
        for d in results[:15]:
            print(d)

if __name__ == "__main__":
    main()
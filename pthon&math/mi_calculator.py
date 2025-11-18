import re
import math
from collections import Counter, defaultdict
from pprint import pprint
import os

# ====================================================================
# 通用工具函数 (与原代码保持一致)
# ====================================================================

def preprocess_char_text(text):
    """
    单个文本任务：预处理，用于字符级分析。
    """
    text = text.lower()
    text = re.sub(r'[^a-z0-9]', '', text)
    return text

def tokenize_text_for_word_analysis(text):
    """
    两个文本任务：预处理并符号化，基于词语级分析。
    """
    text = text.lower()
    text = re.sub(r'[^a-z0-9\s]', ' ', text)
    tokens = re.sub(r'\s+', ' ', text).strip().split(' ')
    return [t for t in tokens if t]

# ====================================================================
# 任务 1：单个文本的点互信息与平均互信息计算 (与原代码保持一致)
# ====================================================================

def calculate_single_text_mi(file_path):
    """
    计算单个文本的相邻符号（字符）点互信息和平均互信息。
    """
    print("## 🤖 任务 1：单个文本的点互信息与平均互信息计算")
    print("--------------------------------------------------")
    
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            raw_text = f.read()
    except FileNotFoundError:
        print(f"错误：文件未找到 '{file_path}'")
        return

    # 1-2. 数据读取与预处理
    processed_text = preprocess_char_text(raw_text)
    
    # 3. 符号定义：相邻字符
    symbols = list(processed_text)
    N = len(symbols) # 文本总符号数
    N_pairs = max(0, N - 1) # 相邻符号对总数

    if N_pairs < 2:
        print("文本符号不足，无法计算相邻符号互信息。")
        return

    print(f"* 文件路径: {file_path}")
    print(f"* 预处理后文本 (仅显示前50字符): {processed_text[:50]}...")
    print(f"* 符号总数 (N): {N}, 相邻符号对总数: {N_pairs}")
    print("-" * 30)
    
    # 4. 统计计算
    count_x = Counter(symbols)
    count_xy = Counter()
    for i in range(N_pairs):
        pair = (symbols[i], symbols[i+1])
        count_xy[pair] += 1
        
    prob_x = {x: count / N for x, count in count_x.items()}
    prob_xy = {pair: count / N_pairs for pair, count in count_xy.items()}
    
    # 5. 互信息计算
    pmi_list = []
    avg_mi = 0.0
    
    for (x, y), p_xy in prob_xy.items():
        p_x = prob_x[x]
        p_y = prob_x.get(y, 1e-10) 
        
        if p_xy == 0 or p_x == 0 or p_y == 0:
            pmi_xy = 0.0
        else:
            try:
                pmi_xy = math.log2(p_xy / (p_x * p_y))
            except ValueError:
                 pmi_xy = 0.0
        
        pmi_list.append({
            'pair': (x, y),
            'PMI': pmi_xy,
            'P(x,y)': p_xy,
            'P(x)': p_x,
            'P(y)': p_y
        })
        
        avg_mi += p_xy * pmi_xy
        
    # 6. 结果输出
    print("### 1. 关键中间数据 (任务 1)")
    print("--- 符号频率 P(x) ---")
    pprint({k: f"{v:.4f}" for k, v in dict(list(prob_x.items())[:10]).items()}) 
    print("\n--- 相邻符号对概率 P(x,y) ---")
    pprint({k: f"{v:.6f}" for k, v in dict(list(prob_xy.items())[:10]).items()}) 
    print("-" * 30)

    print("### 2. 计算结果输出 (任务 1)")
    sorted_pmi = sorted(pmi_list, key=lambda x: x['PMI'], reverse=True)
    print("\n--- 点互信息 (PMI) Top 5 ---")
    for item in sorted_pmi[:5]:
        print(f"Pair: {item['pair']} | PMI: {item['PMI']:.4f} | P(x,y): {item['P(x,y)']:.6f}")
        
    print(f"\n--- 文本平均互信息 (Avg_MI) ---")
    print(f"Avg_MI: {avg_mi:.6f} bits/symbol")
    print("-" * 30)

    print("### 3. 意义与用途总结 (任务 1)")
    print("> **点互信息 (PMI)**")
    print("  - **意义:** 衡量两个具体相邻符号（事件）的关联强度。")
    print("  - **用途:** 语言学分析，自然语言处理中的特征工程，序列数据分析。")
    print("> **平均互信息 (Avg_MI)**")
    print("  - **意义:** 反映文本中相邻符号的整体关联程度。值越高，文本冗余度越高。")
    print("  - **用途:** 文本压缩，评估语言模型的结构复杂度。")
    print("=" * 70)


# ====================================================================
# 任务 2：两个文本间的平均互信息计算 (与原代码保持一致)
# ====================================================================

def calculate_two_text_avg_mi(file_path_a, file_path_b):
    """
    计算两个文本文件之间的平均互信息，基于词语符号化。
    """
    print("\n## 🚀 任务 2：两个文本间的平均互信息计算")
    print("--------------------------------------------------")
    
    try:
        with open(file_path_a, 'r', encoding='utf-8') as f:
            raw_text_a = f.read()
        with open(file_path_b, 'r', encoding='utf-8') as f:
            raw_text_b = f.read()
    except FileNotFoundError as e:
        print(f"错误：文件未找到 {e.filename}")
        return

    # 1-2. 数据读取与预处理
    tokens_a = tokenize_text_for_word_analysis(raw_text_a)
    tokens_b = tokenize_text_for_word_analysis(raw_text_b)
    
    if not tokens_a or not tokens_b:
        print("至少一个文本内容为空，无法计算。")
        return

    print(f"* 文档 A 词语总数 (N_A): {len(tokens_a)}")
    print(f"* 文档 B 词语总数 (N_B): {len(tokens_b)}")
    print("-" * 30)

    # 4. 建立概率模型
    vocab_a = set(tokens_a)
    vocab_b = set(tokens_b)
    full_vocab = vocab_a | vocab_b
    count_a = Counter(tokens_a)
    count_b = Counter(tokens_b)
    N_A = len(tokens_a)
    N_B = len(tokens_b)
    V_size = len(full_vocab)
    
    # 4.3. 共现频率 count_AB(x, y) - 基于对齐的模型
    count_ab = defaultdict(int)
    for word in full_vocab:
        if word in vocab_a and word in vocab_b:
            count_ab[(word, word)] = count_a[word] * count_b[word] 
        
    # 4.4. 概率计算
    prob_a = {x: count / N_A for x, count in count_a.items()}
    prob_b = {y: count / N_B for y, count in count_b.items()}
    
    # P(x, y) = count_AB(x, y) / (V_size)^2
    V_squared = V_size * V_size
    prob_xy = {pair: count / V_squared for pair, count in count_ab.items()}
    
    # 5. 平均互信息计算
    avg_mi_ab = 0.0
    
    for (x, y), p_xy in prob_xy.items():
        p_a_x = prob_a.get(x, 1e-10)
        p_b_y = prob_b.get(y, 1e-10)
        
        if p_xy == 0:
            pmi_xy = 0.0
        else:
            try:
                pmi_xy = math.log2(p_xy / (p_a_x * p_b_y))
            except ValueError:
                pmi_xy = 0.0
        
        avg_mi_ab += p_xy * pmi_xy
        
    # 6. 结果输出
    print("### 1. 关键中间数据 (任务 2)")
    print(f"--- 统一词汇表大小 (V_size): {V_size}")
    print("--- Doc A 概率 P(A)(x) Top 5 ---")
    pprint({k: f"{v:.4f}" for k, v in dict(list(prob_a.items())[:5]).items()}) 
    print("\n--- 共现概率 P(x,y) (仅显示 x=y 的项) Top 5 ---")
    pprint({k: f"{v:.6f}" for k, v in dict(list(prob_xy.items())[:5]).items()}) 
    print("-" * 30)

    print("### 2. 计算结果输出 (任务 2)")
    print(f"\n--- 两个文档间的平均互信息 (Avg_MI) ---")
    print(f"Avg_MI(A, B): {avg_mi_ab:.6f} bits")
    print("-" * 30)

    print("### 3. 意义与用途总结 (任务 2)")
    print("> **两个文本间的平均互信息 (Avg_MI(A, B))**")
    print("  - **意义:** 衡量文档A和文档B符号分布的统计依赖性。")
    print("  - **用途（判定文档相关性）:** Avg_MI 值越大，表示两个文档的统计特性越相似，相关性越高。")
    print("=" * 70)


# ====================================================================
# 运行示例（更新路径）
# ====================================================================

# 请将 BASE_PATH 设置为您提供的文件夹路径
BASE_PATH = r'C:\Users\62685\Desktop\tester'

# 完整的测试文件路径
single_file = os.path.join(BASE_PATH, 'single_text.txt')
doc_a_file = os.path.join(BASE_PATH, 'doc_a.txt')
doc_b_file = os.path.join(BASE_PATH, 'doc_b.txt')


print(f"正在尝试从基础路径加载文件: {BASE_PATH}\n")

# --- 运行任务 1 ---
calculate_single_text_mi(single_file)

# --- 运行任务 2 ---
calculate_two_text_avg_mi(doc_a_file, doc_b_file)
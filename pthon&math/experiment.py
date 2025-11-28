import math
import string
from collections import Counter
import matplotlib.pyplot as plt

# ==========================================
# 1. 数据准备 (模拟不同风格的文本)
# ==========================================

# 作者 A：古典文学风格 (模拟莎士比亚)
text_author_a = """
To be, or not to be, that is the question:
Whether 'tis nobler in the mind to suffer
The slings and arrows of outrageous fortune,
Or to take arms against a sea of troubles
And by opposing end them. To die—to sleep,
No more; and by a sleep to say we end
The heart-ache and the thousand natural shocks
That flesh is heir to: 'tis a consummation
Devoutly to be wish'd. To die, to sleep;
To sleep, perchance to dream—ay, there's the rub:
For in that sleep of death what dreams may come,
When we have shuffled off this mortal coil,
Must give us pause—there's the respect
That makes calamity of so long life.
"""

# 作者 B：技术文档风格 (模拟 Python 教程)
text_author_b = """
Python is an interpreted, high-level and general-purpose programming language.
Python's design philosophy emphasizes code readability with its notable use of significant whitespace.
Its language constructs and object-oriented approach aim to help programmers write clear, logical code for small and large-scale projects.
Python is dynamically-typed and garbage-collected. 
It supports multiple programming paradigms, including structured (particularly, procedural), object-oriented and functional programming.
Python is often described as a "batteries included" language due to its comprehensive standard library.
"""

# 未知文本：(实际上是模仿作者 A 的风格，用来测试)
text_unknown = """
But, for my own part, it was Greek to me. 
I could tell you more news too: Marullus and Flavius, 
for pulling scarfs off Caesar's images, are put to silence. 
Fare you well. There was more foolery yet, if I could remember it.
"""

# ==========================================
# 2. 核心函数定义
# ==========================================

def clean_text(text):
    """
    预处理：转小写，只保留英文字母
    """
    text = text.lower()
    # 过滤掉非字母字符
    valid_chars = [char for char in text if char in string.ascii_lowercase]
    return valid_chars

def get_probability_distribution(chars):
    """
    计算字符出现的概率分布 (应用拉普拉斯平滑)
    """
    # 统计字符频次
    counts = Counter(chars)
    
    # 拉普拉斯平滑：确保 a-z 每个字母至少出现 1 次，防止概率为 0
    # 这一步对于 KL 散度计算至关重要
    alphabet = string.ascii_lowercase
    for letter in alphabet:
        counts[letter] += 1
        
    total_count = sum(counts.values())
    
    # 计算概率
    probs = {char: count / total_count for char, count in counts.items()}
    
    # 按照 a-z 排序返回列表，保证顺序一致
    sorted_probs = [probs[char] for char in alphabet]
    return sorted_probs

def kl_divergence(p, q):
    """
    计算相对熵 D(P || Q)
    P: 未知文本的分布 (真实分布)
    Q: 候选作者的分布 (拟合分布)
    """
    kl_sum = 0.0
    for pi, qi in zip(p, q):
        # 公式: sum( P(x) * log2( P(x) / Q(x) ) )
        kl_sum += pi * math.log2(pi / qi)
    return kl_sum

# ==========================================
# 3. 实验执行
# ==========================================

def run_experiment():
    print("-" * 30)
    print("实验开始：利用相对熵判别作者")
    print("-" * 30)

    # 1. 处理文本
    chars_a = clean_text(text_author_a)
    chars_b = clean_text(text_author_b)
    chars_unknown = clean_text(text_unknown)

    # 2. 获取概率分布
    dist_a = get_probability_distribution(chars_a) # Q_A
    dist_b = get_probability_distribution(chars_b) # Q_B
    dist_unknown = get_probability_distribution(chars_unknown) # P

    # 3. 计算 KL 散度
    # D(Unknown || Author A)
    kl_a = kl_divergence(dist_unknown, dist_a)
    
    # D(Unknown || Author B)
    kl_b = kl_divergence(dist_unknown, dist_b)

    # 4. 输出结果
    print(f"未知文本 vs 作者 A (古典) 的 KL 散度: {kl_a:.4f} bits")
    print(f"未知文本 vs 作者 B (技术) 的 KL 散度: {kl_b:.4f} bits")
    print("-" * 30)

    # 5. 判别结论
    if kl_a < kl_b:
        print(">>> 结论: 未知文本更像是 [作者 A] 写的。")
        print("    (原因：与作者 A 的信息分布差异更小)")
    else:
        print(">>> 结论: 未知文本更像是 [作者 B] 写的。")
        print("    (原因：与作者 B 的信息分布差异更小)")
        
    return dist_a, dist_b, dist_unknown

# 运行实验
dist_a, dist_b, dist_u = run_experiment()

# 简单的图表展示 'e', 't', 'h', 'z' 等几个关键字母的频率对比
labels = list(string.ascii_lowercase)
x = range(len(labels))

plt.figure(figsize=(12, 6))
plt.plot(labels, dist_a, label='Author A (Classical)', marker='o')
plt.plot(labels, dist_b, label='Author B (Tech)', marker='x')
plt.plot(labels, dist_u, label='Unknown Text', linestyle='--', linewidth=2, color='red')

plt.title("Character Frequency Distribution Comparison")
plt.xlabel("Characters")
plt.ylabel("Probability")
plt.legend()
plt.grid(True, alpha=0.3)
# plt.show() 
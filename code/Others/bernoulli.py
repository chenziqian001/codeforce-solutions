import numpy as np
import matplotlib.pyplot as plt

def simulate_bernoulli_process(p, n):
    return np.random.binomial(1, p, n)

# 参数设置
p = 0.3  # 成功概率
n = 100  # 试验次数

# 模拟贝努利过程
bernoulli_seq = simulate_bernoulli_process(p, n)

print("贝努利过程序列：")
print(bernoulli_seq)

# 可视化
plt.figure(figsize=(12, 3))
plt.stem(range(1, n+1), bernoulli_seq, basefmt=" ")
plt.xlabel('试验次数')
plt.ylabel('结果 (0=失败, 1=成功)')
plt.title(f'贝努利过程模拟 (p={p}, n={n})')
plt.ylim(-0.1, 1.1)
plt.show()

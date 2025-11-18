import math
from collections import Counter

def self_information(p):
    if p == 0:
        return 0
    return -math.log2(p)

def entropy(prob_dict):
    H = 0
    for p in prob_dict.values():
        H += p * self_information(p)
    return H

def process_english_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        text = f.read().lower()
    letters = [c for c in text if 'a' <= c <= 'z']
    total = len(letters)
    counter = Counter(letters)
    prob = {char: count/total for char, count in counter.items()}
    return prob

def process_chinese_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        text = f.read()
    chinese_chars = [c for c in text if '\u4e00' <= c <= '\u9fff']
    total = len(chinese_chars)
    counter = Counter(chinese_chars)
    prob = {char: count/total for char, count in counter.items()}
    return prob


if __name__ == "__main__":
    english_file = r'C:\Users\62685\Desktop\eg.txt'
    chinese_file = r'C:\Users\62685\Desktop\ch.txt'

    eng_prob = process_english_file(english_file)
    chi_prob = process_chinese_file(chinese_file)

    H_eng = entropy(eng_prob)
    H_chi = entropy(chi_prob)

    print("英文文本信息熵 H(X) =", H_eng)
    print("中文文本信息熵 H(X) =", H_chi)



with open("simple_struct.dat","wb") as f:
    f.write(sn)
    f.wrte(s.encode)
    






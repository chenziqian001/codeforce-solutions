import concurrent.futures
import platform
import re
import subprocess


def ping_ip(ip):
  """使用系统 ping 命令测试单个 IP 是否存活"""
  param = "-n" if platform.system().lower() == "windows" else "-c"
  timeout = "-w" if platform.system().lower() == "windows" else "-W"
  timeout_value = "100" if platform.system().lower() == "windows" else "1"

  command = ["ping", param, "1", timeout, timeout_value, ip]
  try:
    result = subprocess.run(
        command,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        timeout=1.5,
    )
    return ip if result.returncode == 0 else None
  except subprocess.TimeoutExpired:
    return None
  except Exception:
    return None


def get_arp_table():
  """获取系统的 ARP 缓存表，返回 IP 到 MAC 的映射字典"""
  arp_command = ["arp", "-a"]
  try:
    output = (
        subprocess.check_output(arp_command, universal_newlines=True)
        .encode("utf-8", errors="ignore")
        .decode("utf-8", errors="ignore")
    )
  except Exception:
    return {}

  arp_table = {}
  # 正则匹配常见的 IP 和 MAC 地址格式
  pattern = re.compile(
      r"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})\s+([0-9a-fA-F:-]{12,17})"
  )
  for line in output.splitlines():
    match = pattern.search(line)
    if match:
      ip, mac = match.groups()
      arp_table[ip] = mac
  return arp_table


def get_local_subnet():
  """尝试获取当前机器的局域网网段（仅作简单参考提示）"""
  # 这里默认扫描常见的家庭/小型局域网网段 192.168.1.X 或 192.168.0.X
  # 也可以根据实际情况修改
  return "192.168.1"


def scan_network(subnet):
  print(f"正在扫描网段 {subnet}.1 ~ {subnet}.254 中的设备，请稍候...")
  ip_list = [f"{subnet}.{i}" for i in range(1, 255)]

  active_ips = []
  # 使用线程池并发 ping，提高扫描速度
  with concurrent.futures.ThreadPoolExecutor(max_workers=100) as executor:
    results = executor.map(ping_ip, ip_list)
    for ip in results:
      if ip:
        active_ips.append(ip)

  return active_ips


if __name__ == "__main__":
  # 您可以根据实际的 Wi-Fi 网段修改前三段（例如 "192.168.0" 或 "192.168.31"）
  subnet = "10.126.64"

  active_ips = scan_network(subnet)
  arp_table = get_arp_table()

  print("\n当前 Wi-Fi 下发现的设备：")
  print("-" * 40)
  print(f"{'IP 地址':<18} {'MAC 地址':<18}")
  print("-" * 40)

  count = 0
  for ip in active_ips:
    mac = arp_table.get(ip, "未知 / 缓存未更新")
    print(f"{ip:<18} {mac:<18}")
    count += 1

  print("-" * 40)
  print(f"扫描完成，共找到 {count} 个在线设备。")
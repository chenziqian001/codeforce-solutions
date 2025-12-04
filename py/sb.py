import random

# --- 基类：Character (角色) ---
class Character:
    """
    所有能打架的单位都继承这个类，包括玩家和怪物。
    """
    def __init__(self, name, atk, defense, hp):
        self.name = name
        self.atk = atk  # 攻击力 (Attack)
        self.defense = defense
        self.hp = hp    # 当前生命值 (Health Points)
        self.max_hp = hp # 最大生命值，方便回血

    def is_alive(self):
        """看看角色还有没有气。"""
        return self.hp > 0

    def take_damage(self, damage):
        """
        受伤计算逻辑。
        核心规则：伤害至少为 1 点，防止防御堆太高打不动。
        """
        # 实际伤害 = 攻击力 - 防御力
        actual_damage = damage - self.defense
        
        # 附加规则 1: 最低伤害 1 点
        # 这就是传说中的“破防”机制
        actual_damage = max(1, actual_damage)
        
        # 扣血，但不允许扣成负数
        self.hp = max(0, self.hp - actual_damage)
            
        print(f"--- {self.name} 惨遭 {actual_damage} 点伤害 ({damage} 攻击 - {self.defense} 防御) ---")
        return actual_damage

    def attack_target(self, target):
        """上去就是一刀 (或者一口)"""
        print(f"\n{self.name} 狠狠地攻击 {target.name}！")
        target.take_damage(self.atk)

# --- 子类：Player (玩家) ---
class Player(Character):
    """
    主角类。有等级、经验和升级逻辑。
    """
    def __init__(self, name="英雄", atk=10, defense=5, hp=50):
        super().__init__(name, atk, defense, hp)
        self.lvl = 1
        self.exp = 0
        self.exp_to_next_lvl = 100
        self.gold = 0 # 金币用 gold 感觉更 RPG
    
    def display_stats(self):
        """打印角色面板，方便玩家查看。"""
        print("="*30)
        print(f"| {self.name} - Lv.{self.lvl}")
        print(f"| HP: {self.hp}/{self.max_hp}")
        print(f"| 攻击: {self.atk} | 防御: {self.defense}")
        print(f"| EXP: {self.exp}/{self.exp_to_next_lvl} | 💰: {self.gold}")
        print("="*30)

    def gain_exp(self, amount):
        """收经验，不够就接着收，直到不升级为止。"""
        self.exp += amount
        print(f"获得了 {amount} 点经验！")
        while self.exp >= self.exp_to_next_lvl:
            self.level_up()

    def level_up(self):
        """升级啦！属性暴涨一波。"""
        self.lvl += 1
        self.exp -= self.exp_to_next_lvl
        # 经验需求递增 50%
        self.exp_to_next_lvl = int(self.exp_to_next_lvl * 1.5) 
        
        # 属性成长，数值就随便定一下
        self.max_hp += 10
        self.hp = self.max_hp # 升级就满血
        self.atk += 2
        self.defense += 1
        
        print("\n🎉🎉🎉 恭喜！脱胎换骨，升到新等级！ 🎉🎉🎉")
        self.display_stats()
        
    def rest(self):
        """战斗后回血，回个三分之一，挺合理的。"""
        recover_amount = self.max_hp // 3
        self.hp = min(self.max_hp, self.hp + recover_amount) # 不超过最大血量
        
        print(f"\n💧 你找个地方坐下休息，恢复了 {recover_amount} 点生命值。")
        print(f"当前生命值: {self.hp}/{self.max_hp}")


# --- 子类：Enemy (敌人/怪物) ---
class Enemy(Character):
    """
    怪物类。属性跟玩家等级挂钩。
    """
    def __init__(self, level, name=None):
        # 动态生成属性，带点随机性
        base_hp = 15 + level * 5
        base_atk = 5 + level * 2
        base_def = 2 + level * 1
        
        hp = int(base_hp * random.uniform(0.9, 1.1)) # 属性随机波动 10%
        atk = int(base_atk * random.uniform(0.9, 1.1))
        defense = int(base_def * random.uniform(0.9, 1.1))
        
        # 怪物名字列表
        if name is None:
            name_options = ["哥布林", "野狼", "骷髅兵", "史莱姆", "恶魔幼崽", "狂暴兔"]
            name = random.choice(name_options)

        super().__init__(name, atk, defense, hp)
        self.lvl = level # 方便显示
        self.exp_reward = level * 20
        self.gold_drop = level * 5
        
    def display_stats(self):
        """显示怪物状态，简洁点。"""
        print(f"  敌人: {self.name} Lv.{self.lvl} | HP: {self.hp}/{self.max_hp}")


# --- 战斗管理：Map/Encounter ---
class Encounter:
    """
    负责管理和生成战斗遭遇。
    """
    def __init__(self):
        self.enemies = []
        self.stage = 1

    def generate_enemies(self, player_level):
        """根据玩家等级，丢出一批怪。"""
        self.enemies.clear()
        
        # 敌人数量：1 到 3 个，等级高了多一个
        num_enemies = random.randint(1, 3) + (player_level // 5)
        num_enemies = min(num_enemies, 5) 
        
        print(f"\n--- 第 {self.stage} 关：草丛里跳出来 {num_enemies} 个家伙！ ---")
        
        for _ in range(num_enemies):
            # 怪物等级：玩家等级 ±1
            enemy_level = max(1, player_level + random.randint(-1, 1))
            enemy = Enemy(level=enemy_level)
            self.enemies.append(enemy)
        
        self.stage += 1
        return self.enemies

# --- 主控：Game ---
class Game:
    """
    游戏主流程，控制开局、回合和结束。
    """
    def __init__(self):
        self.player = Player()
        self.encounter = Encounter()

    def start_game(self):
        """游戏开始主循环，打不过就GG。"""
        print("===== 欢迎来到简陋的文本冒险 =====")
        self.player.name = input("你叫啥名字？(回车默认 '无名英雄'): ") or "无名英雄"
        self.player.display_stats()
        
        while self.player.is_alive():
            enemies = self.encounter.generate_enemies(self.player.lvl)
            self.battle_loop(enemies)
            
            if not self.player.is_alive():
                self.game_over()
                break
            
            self.post_battle_menu()

    def battle_loop(self, enemies):
        """一轮硬仗，直到一方死光。"""
        print("\n--- 战斗开始！ ---")
        
        # 过滤掉死掉的怪物
        living_enemies = [e for e in enemies if e.is_alive()]
        
        while self.player.is_alive() and living_enemies:
            print("\n--- 你的回合！A上去！ ---")
            self.player.display_stats()
            
            # 1. 玩家选择目标
            print("【面前的威胁】:")
            for idx, enemy in enumerate(living_enemies):
                print(f"  [{idx + 1}] ", end="")
                enemy.display_stats() # 调用怪物自己的显示方法
            
            # 2. 玩家行动输入
            while True:
                try:
                    choice = input("选个目标 (1-{})：".format(len(living_enemies)))
                    target_index = int(choice) - 1
                    
                    if 0 <= target_index < len(living_enemies):
                        target = living_enemies[target_index]
                        self.player.attack_target(target)
                        
                        if not target.is_alive():
                            print(f"🎉 {target.name} 倒下了！")
                            living_enemies.remove(target)
                            
                            # 结算奖励
                            self.player.gain_exp(target.exp_reward)
                            self.player.gold += target.gold_drop
                            print(f"捡到了 {target.gold_drop} 金币。")
                        break
                    else:
                        print("选错了，好好看看编号。")
                except ValueError:
                    print("大哥，输个数字行不行？")
            
            # 3. 怪物反击
            if living_enemies:
                print("\n--- 怪物们的回合，它们开始反扑... ---")
                for enemy in living_enemies:
                    if enemy.is_alive():
                        enemy.attack_target(self.player)
                        if not self.player.is_alive():
                            break

    def post_battle_menu(self):
        """打完收工，喘口气。"""
        print("\n===== 战斗结束，你赢了！ =====")
        self.player.display_stats()

        while True:
            print("\n--- 下一步干啥？ ---")
            action = input("[1] 继续往前冲 [2] 休息回血 [R/r]：").lower()
            
            if action in ('1', ''):
                break
            elif action in ('2', 'r'):
                self.player.rest()
            else:
                print("搞啥呢，选项里没有这个。")

    def game_over(self):
        """GameOver 画面。"""
        print("\n==============================")
        print("||                          ||")
        print("||      💥 你被击败了 💥    ||")
        print("||                          ||")
        print("==============================")
        print(f"英雄 {self.player.name} 最终等级定格在: {self.player.lvl}")

if __name__ == "__main__":
    game = Game()
    game.start_game()
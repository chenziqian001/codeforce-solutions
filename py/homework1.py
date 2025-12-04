import random

# --- 1. Character（基类） ---
class Character:
    """
    基类：包含所有角色（玩家和敌人）的通用属性和行为。
    属性: attack (攻击力), defense (防御力), health (生命值), max_health (最大生命值)。
    """
    def __init__(self, name, attack, defense, health):
        self.name = name
        self.attack = attack
        self.defense = defense
        self.health = health
        self.max_health = health

    def is_alive(self):
        """检查角色是否存活。"""
        return self.health > 0

    def take_damage(self, damage):
        """
        处理受伤逻辑。
        规则: 实际伤害 = max(1, 攻击力 - 防御力)。
        """
        # 计算理论伤害
        actual_damage = damage - self.defense
        
        # 附加规则 1: 最低伤害 1 点
        if actual_damage <= 0:
            actual_damage = 1
        
        # 扣除生命值
        self.health -= actual_damage
        if self.health < 0:
            self.health = 0
            
        print(f"--- {self.name} 受到 {actual_damage} 点伤害 ({damage} - {self.defense}) ---")
        return actual_damage

    def attack_target(self, target):
        """对目标发动攻击。"""
        print(f"\n{self.name} 攻击 {target.name}！")
        target.take_damage(self.attack)

# --- 2. Player（子类） ---
class Player(Character):
    """
    子类：玩家角色，增加等级和经验值。
    """
    def __init__(self, name="英雄", attack=10, defense=5, health=50):
        # 调用父类构造器初始化基础属性
        super().__init__(name, attack, defense, health)
        self.level = 1
        self.exp = 0
        self.exp_to_next_level = 100
        self.money = 0
    
    def display_stats(self):
        """显示玩家状态。"""
        print("="*30)
        print(f"| {self.name} - Lv.{self.level}")
        print(f"| HP: {self.health}/{self.max_health}")
        print(f"| 攻: {self.attack} | 防: {self.defense}")
        print(f"| 经验: {self.exp}/{self.exp_to_next_level} | 金币: {self.money}")
        print("="*30)

    def gain_exp(self, amount):
        """获得经验值并检查是否升级。"""
        self.exp += amount
        print(f"获得了 {amount} 点经验。")
        while self.exp >= self.exp_to_next_level:
            self.level_up()

    def level_up(self):
        """玩家升级逻辑。"""
        self.level += 1
        self.exp -= self.exp_to_next_level
        self.exp_to_next_level = int(self.exp_to_next_level * 1.5) # 下一等级所需经验增加
        
        # 属性成长 (基础值增加 10% 并固定数值增加)
        self.max_health += 10
        self.health = self.max_health # 升级时生命值全满
        self.attack += 2
        self.defense += 1
        
        print("\n🎉🎉🎉 恭喜！你升级了！ 🎉🎉🎉")
        self.display_stats()
        
    def rest(self):
        """附加内容 2: 休息选项，恢复一定的生命值。"""
        recover_amount = self.max_health // 3 # 恢复最大生命值的 1/3
        self.health += recover_amount
        if self.health > self.max_health:
            self.health = self.max_health
        print(f"\n💧 你选择了休息，恢复了 {recover_amount} 点生命值。")
        print(f"当前生命值: {self.health}/{self.max_health}")


# --- 3. Enemy（子类） ---
class Enemy(Character):
    """
    子类：敌人角色，依据关卡动态生成属性。
    """
    def __init__(self, level, name=None):
        # 动态生成属性 (与关卡 level 挂钩)
        base_hp = 15 + level * 5
        base_atk = 5 + level * 2
        base_def = 2 + level * 1
        
        # 随机波动属性
        health = int(base_hp * random.uniform(0.9, 1.1))
        attack = int(base_atk * random.uniform(0.9, 1.1))
        defense = int(base_def * random.uniform(0.9, 1.1))
        
        # 随机选择敌人名字
        if name is None:
            name_options = ["哥布林", "野狼", "骷髅兵", "史莱姆", "恶魔幼崽"]
            name = random.choice(name_options)

        super().__init__(name, attack, defense, health)
        self.level = level # 方便显示
        self.exp_reward = level * 20
        self.money_drop = level * 5
        
    def display_stats(self):
        """显示敌人状态。"""
        print(f"| 敌人: {self.name} Lv.{self.level}")
        print(f"| HP: {self.health}/{self.max_health} | 攻: {self.attack} | 防: {self.defense}")


# --- 4. Map (或 Encounter Manager) ---
class Map:
    """
    负责生成敌人，维护敌人列表。
    """
    def __init__(self):
        self.enemies = []
        self.current_stage = 1

    def generate_enemies(self, player_level):
        """根据玩家等级生成一批敌人。"""
        self.enemies.clear()
        
        # 关卡难度系数 (敌人数量)
        num_enemies = random.randint(1, 2) + (player_level // 3)
        num_enemies = min(num_enemies, 5) # 最多 5 个敌人
        
        print(f"\n--- 第 {self.current_stage} 关：生成 {num_enemies} 个敌人！ ---")
        
        for i in range(num_enemies):
            # 敌人等级通常与玩家等级接近
            enemy_level = player_level + random.randint(-1, 1)
            enemy_level = max(1, enemy_level)
            enemy = Enemy(level=enemy_level)
            self.enemies.append(enemy)
        
        self.current_stage += 1
        return self.enemies

# --- 5. Game（主流程控制） ---
class Game:
    """
    主流程控制。
    """
    def __init__(self):
        self.player = Player()
        self.map = Map()

    def start_game(self):
        """游戏开始主循环。"""
        print("===== 欢迎来到回合制冒险游戏 =====")
        self.player.name = input("请输入你的英雄名称: ") or "无名英雄"
        self.player.display_stats()
        
        while self.player.is_alive():
            enemies = self.map.generate_enemies(self.player.level)
            self.battle_loop(enemies)
            
            if not self.player.is_alive():
                self.game_over()
                break
            
            self.post_battle_menu()

    def battle_loop(self, enemies):
        """处理一轮战斗流程。"""
        print("\n--- 战斗开始 ---")
        
        # 敌人的目标列表
        living_enemies = [e for e in enemies if e.is_alive()]
        
        # 回合循环，直到所有敌人死亡或玩家死亡
        while self.player.is_alive() and living_enemies:
            print("\n--- 你的回合 ---")
            self.player.display_stats()
            
            # 1. 显示敌人列表
            print("当前敌人:")
            for idx, enemy in enumerate(living_enemies):
                print(f"  [{idx + 1}] {enemy.name} (Lv.{enemy.level}) HP: {enemy.health}/{enemy.max_health}")
            
            # 2. 玩家选择目标和行动
            while True:
                try:
                    choice = input("请选择攻击目标编号 (1-{})：".format(len(living_enemies)))
                    target_index = int(choice) - 1
                    if 0 <= target_index < len(living_enemies):
                        target = living_enemies[target_index]
                        self.player.attack_target(target)
                        
                        if not target.is_alive():
                            print(f"🎉 {target.name} 被击败！")
                            living_enemies.remove(target)
                            
                            # 奖励
                            self.player.gain_exp(target.exp_reward)
                            self.player.money += target.money_drop
                            print(f"获得了 {target.money_drop} 金币。")

                        break
                    else:
                        print("输入无效，请重新选择。")
                except ValueError:
                    print("请输入数字。")
            
            # 3. 敌人回合
            if living_enemies:
                print("\n--- 敌人的回合 ---")
                for enemy in living_enemies:
                    if enemy.is_alive():
                        enemy.attack_target(self.player)
                        if not self.player.is_alive():
                            break

    def post_battle_menu(self):
        """战斗结束后，进入菜单选择恢复。"""
        print("\n===== 战斗胜利！ =====")
        self.player.display_stats()

        while True:
            print("\n--- 战后行动 ---")
            action = input("[1] 继续冒险 [2] 休息恢复 [R/r]: ").lower()
            
            if action == '1' or action == '':
                break
            elif action == '2' or action == 'r':
                self.player.rest()
            else:
                print("无效选项，请重新选择。")


    def game_over(self):
        """游戏结束。"""
        print("\n==============================")
        print("||                          ||")
        print("||        游戏结束          ||")
        print("||                          ||")
        print("==============================")
        print(f"英雄 {self.player.name} 最终等级: {self.player.level}")

if __name__ == "__main__":
    # 运行游戏
    game = Game()
    game.start_game()
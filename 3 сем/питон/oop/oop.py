from random import randint

class Hero:
    name = ""
    hp = 100
    armor = 50
    dm = 10
    crit_dm = 7
    crit_chance = 18
    def __init__(self, name):
        self.name = name
    def Hero_name(self):
        return self.name
    def Hero_hp(self):
        return self.hp
    def Hero_dm(self):
        return self.dm
    def heal_me(self, hh):
        hp+=hh
    def status(self):
        print(self.name, "STATS:", "\n", "Hp:",self.hp, "Armor:",self.armor)

    def message (self):
        if(self.hp <= 0 and self.armor <= 0):
            print("YOU   | HP: 0 ARMOR: 0")
            print("YOU DIED")
        else:
            print("YOU   | HP: ", self.hp, " ARMOR: ", self.armor)

    def damage(self, e_dm):
        if (self.armor > 0):
            self.armor -= e_dm
            if(self.armor < 0):
                self.hp -= abs(self.armor)
            self.message()
                
        elif(self.hp > 0 and self.armor <= 0):
            self.hp -= e_dm
            self.message()
        else:
            self.message()
        
class Hero_pet(Hero):
    heal_hp = 15
    heal_count = 3
    def heal(self):
        self.heal_count -= 1
        if(self.heal_count <= 0):
            print("heal 0")
        else:
            Hero.hp += self.heal_hp
            print(Hero.hp)

class Enemy:
    hp = 100
    armor = 50
    dm = 10
    def Enemy_hp(self):
        return self.hp
    def Enemy_dm(self):
        return self.dm

    def status(self):
        print("ENEMY STATS:", "\n", "Hp:",self.hp, "Armor:",self.armor)
    
    def message (self):
        if(self.hp <= 0 and self.armor <= 0):
            print("ENEMY | HP: 0 ARMOR: 0")
            print("ENEMY DIED")
        else:
            print("ENEMY | HP: ", self.hp, " ARMOR: ", self.armor)

    def damage(self, e_dm):
        if (self.armor > 0):
            self.armor -= e_dm
            if(self.armor < 0):
                self.hp -= abs(self.armor)
            self.message()    
        elif(self.hp > 0 and self.armor <= 0):
            self.hp -= e_dm
            self.message()
        else:
            self.message()

player = Hero("CEMEH_BAKIN")
pet = Hero_pet("bIT_A6ahA")
enemy_bot = Enemy()
print(player.Hero_name(),"vs Enemy", "\n",)
player.status()
enemy_bot.status()
print("\n", "Fight!", "\n")

print("test -_-")

while(player.Hero_hp() > 0 or enemy_bot.Enemy_hp() > 0):
    key=0
    while(True):
        key = int(input("1| ATTACK\n2| DEFENCE\n3| HEAL\n"))
        if (key<=3 and key > 0):
            break
        else: 
            print("INCORRECT")

    if(key == 1):
        print("key 1")
        enemy_bot.damage(player.Hero_dm())

    elif(key == 2):
        print("key 2")
        
    elif(key == 3):
        print("key 3")
        pet.heal()

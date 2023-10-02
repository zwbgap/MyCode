class Game(object):
    # 历史最高分
    top_score = 0

    def __init__(self,player_name):
        self.player_name = player_name
    
    @staticmethod
    def show_help():
        print("展示帮助信息...")
    
    @classmethod
    def show_top_score(cls):
        print(f'历史最高分: {cls.top_score}')

    def start_game(self):
        print(f'玩家 {self.player_name} 请开始游戏')

# 1、查看游戏帮助
Game.show_help()
# 2、显示历史最高分
Game.show_top_score()
# 3、开始游戏
game = Game('Joker')
game.start_game()


class MusicPlayer(object):
    def __new__(cls, *args, **kwargs):
        print('创建对象，分配空间')
        instance = super().__new__(cls)
        return instance
    
    def __init__(self):
        print('播放器初始化')

player = MusicPlayer()
print(player)

class MusicPlayer(object):
    instance = None
    def __new__(cls, *args, **kwargs):
        if cls.instance is None:
            cls.instance = super().__new__(cls)
        return cls.instance

        
player1 = MusicPlayer()
print(player1)

player2 = MusicPlayer()
print(player2)



class NPC():
    def __init__(self, color):
        self.color = color

    def say(self):
        print(self.color)

    def pour(self):
        print("把水倒出來")


cup1 = Cup("blue")
cup2 = Cup("red")

cup1.say()
cup2.say()

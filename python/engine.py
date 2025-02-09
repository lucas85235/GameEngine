import game_engine
import tkinter as tk
from threading import Thread

class EngineUI:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Game Engine UI")

        self.engine = game_engine.Engine()

        self.start_button = tk.Button(self.window, text="Start Engine", command=self.start_engine)
        self.start_button.pack()

        self.stop_button = tk.Button(self.window, text="Stop Engine", command=self.stop_engine)
        self.stop_button.pack()

        self.window.mainloop()

    def start_engine(self):
        self.engine_thread = Thread(target=self.engine.run)
        self.engine_thread.start()

    def stop_engine(self):
        self.engine.stop()

if __name__ == "__main__":
    EngineUI()

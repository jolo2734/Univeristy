from kivy.app import App
from kivy.uix.floatlayout import FloatLayout
from kivy.lang import Builder

Builder.load_file("myfile.kv")

class KivyButton (App, FloatLayout):
    def build(self):

        return self


KivyButton().run()
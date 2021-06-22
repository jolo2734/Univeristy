from kivy.app import App
from kivy.uix.button import Button
from functools import partial


class FirstKivy(App):

    def disable(self, instance, *args):
        instance.disabled = True

    def update(self, instance, *args):
        instance.text = "I am Disabled"

    def build(self):
        mybtn = Button(text="Click me to disable")
        mybtn.bind(on_press=partial(self.disable, mybtn))
        mybtn.bind(on_press=partial(self.update, mybtn))

        return mybtn


FirstKivy().run()

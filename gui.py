# Imports ophalen score
import serial
from time import sleep

# Imports voor GUI
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.graphics import Color, Rectangle

SIZE = 150


class BackgroundLabel(Label):
    def __init__(self, r, g, b, a, **kwargs):
        super(BackgroundLabel, self).__init__(**kwargs)
        self.r = r
        self.g = g
        self.b = b
        self.a = a

    def on_size(self, *args):
        self.canvas.before.clear()
        with self.canvas.before:
            Color(self.r, self.g, self.b, self.a)
            Rectangle(pos=self.pos, size=self.size)


class ScorebordApp(App):

    def build(self):
        layout = GridLayout(rows=2)
        secondRow = GridLayout(cols=5)

        rood = BackgroundLabel(
            text="10",
            font_size=SIZE,
            r=1, g=0, b=0, a=1
        )

        groen = BackgroundLabel(
            text="0",
            font_size=SIZE,
            r=0, g=1, b=0, a=1
        )

        geel = BackgroundLabel(
            text="0",
            font_size=SIZE,
            color=(0, 0, 0, 1),
            r=1, g=1, b=0, a=1
        )

        wit = BackgroundLabel(
            text="0",
            font_size=SIZE,
            color=(0, 0, 0, 1),
            r=1, g=1, b=1, a=1
        )
        blauw = BackgroundLabel(
            text="0",
            font_size=SIZE,
            r=0, g=0, b=1, a=1
        )

        secondRow.add_widget(rood)
        secondRow.add_widget(wit)
        secondRow.add_widget(blauw)
        secondRow.add_widget(groen)
        secondRow.add_widget(geel)

        layout.add_widget(
            Label(text="Wolven Quiz", size_hint_y=0.25, font_size=50))
        layout.add_widget(secondRow)

        return layout


ScorebordApp().run()

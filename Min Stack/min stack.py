{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class MinStack:\
\
    def __init__(self):\
        self.a = []\
        self.b = []\
\
    def push(self, val: int) -> None:\
        self.a.append(val)\
        if (len(self.b) == 0 or val <= self.b[-1]):\
            self.b.append(val)\
\
    def pop(self) -> None:\
        if (len(self.a) > 0):\
            if (self.a[-1] == self.b[-1]):\
                self.b.pop()\
            self.a.pop()\
\
    def top(self) -> int:\
        return self.a[-1]\
\
    def getMin(self) -> int:\
        return self.b[-1]\
\
\
# Your MinStack object will be instantiated and called as such:\
# obj = MinStack()\
# obj.push(val)\
# obj.pop()\
# param_3 = obj.top()\
# param_4 = obj.getMin()}
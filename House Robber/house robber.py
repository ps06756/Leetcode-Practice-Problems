{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def rob(self, nums: List[int]) -> int:\
        self.dp = \{ \}\
        self.nums = nums\
        \
        return self.f(0, True)\
        \
    def f(self, i, canRob):\
        if (i == len(self.nums) - 1):\
            if (canRob == True):\
                return self.nums[i]\
            else:\
                return 0\
        else:\
            if ((i, canRob) not in self.dp):\
                if (canRob == True):\
                    self.dp[(i, canRob)] = max(self.nums[i] + self.f(i + 1, False),\
                                         self.f(i + 1, True))\
                else:\
                    self.dp[(i, canRob)] = self.f(i + 1, True)\
            return self.dp[(i, canRob)]}
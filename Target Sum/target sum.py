{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    \
    \
    def f(self, i, ct):\
        if (i < len(self.nums) - 1):\
            key = (i, ct)\
            if (key in self.ht):\
                return self.ht[key]\
            self.ht[key] = self.f(i + 1, ct - self.nums[i]) + self.f(i + 1, ct + self.nums[i])\
            return self.ht[key]\
        else:\
            if (ct == 0 and self.nums[i] == 0):\
                return 2\
            elif (abs(ct) == abs(self.nums[i])):\
                return 1\
            else:\
                return 0\
    \
    def findTargetSumWays(self, nums: List[int], target: int) -> int:\
        self.nums = nums\
        self.ht = \{ \}\
        \
        return self.f(0, target)}
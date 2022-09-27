{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def minEatingSpeed(self, piles: List[int], h: int) -> int:\
        start = 1\
        end = max(piles)\
        ans = end\
        \
        while (start <= end):\
            mid = (start + end)//2\
            if (self.countHours(piles, mid) > h):\
                start = mid + 1\
            else:\
                ans = mid\
                end = mid - 1\
        return ans\
    \
    def countHours(self, piles, speed):\
        noOfHours = 0\
        for pile in piles:\
            noOfHours += math.ceil(pile/speed)\
        \
        return noOfHours\
        }
{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def productExceptSelf(self, nums: List[int]) -> List[int]:\
        left = [1]\
        n = len(nums)\
        for i in range(1, n):\
            left.append(left[i-1]*nums[i-1])\
        \
        right = [1]*(n+1)\
        for i in range(n-2, -1, -1):\
            right[i] = right[i+1]*nums[i+1]\
        \
        output = []\
        for i in range(n):\
            output.append(left[i]*right[i])\
        \
        return output\
        }
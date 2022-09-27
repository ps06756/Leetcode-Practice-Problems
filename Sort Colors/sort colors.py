{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def sortColors(self, nums: List[int]) -> None:\
        """\
        Do not return anything, modify nums in-place instead.\
        """\
        \
        left = 0\
        right = len(nums) - 1\
        \
        i = 0\
        \
        while i <= right:\
            if (nums[i] == 0):\
                nums[i], nums[left] = nums[left],nums[i]\
                left += 1\
                i += 1\
            elif (nums[i] == 2):\
                nums[i], nums[right] = nums[right], nums[i]\
                right -= 1\
            else:\
                i += 1\
        \
        }
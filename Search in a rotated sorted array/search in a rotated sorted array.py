{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def search(self, arr: List[int], target: int) -> int:\
        start= 0\
        end = len(arr) - 1\
        ans = -1\
        \
        while start <= end:\
            mid = (start + end)//2\
            if (arr[mid] >= arr[0] and target < arr[0]):\
                start = mid + 1\
            elif (arr[mid] < arr[0] and target >= arr[0]):\
                end = mid - 1\
            else:\
                if (arr[mid] < target):\
                    start = mid + 1\
                elif (arr[mid] > target):\
                    end = mid - 1\
                else:\
                    ans = mid\
                    break\
        return ans}
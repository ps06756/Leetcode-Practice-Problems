{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:\
        self.dp = \{ \}\
        self.text1 = text1\
        self.text2 = text2\
        n = len(text1)\
        m = len(text2)\
        \
        return self.lcs(n - 1, m - 1)\
        \
    def lcs(self, i, j):\
        if (i == -1 or j == -1):\
            return 0\
        else:\
            if ((i, j) not in self.dp):\
                if (self.text1[i] == self.text2[j]):\
                    self.dp[(i, j)] = self.lcs(i - 1, j - 1) + 1\
                else:\
                    self.dp[(i, j)] = max(self.lcs(i-1, j), self.lcs(i, j-1))\
            return self.dp[(i, j)]}
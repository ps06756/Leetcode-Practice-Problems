{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def isValid(self, s: str) -> bool:\
        st = []\
        for ch in s:\
            if (self.isOpening(ch)):\
                st.append(ch)\
            else:\
                if (len(st) == 0):\
                    return False\
                else:\
                    if (self.doesMatch(st[-1], ch)):\
                        st.pop()\
                    else:\
                        return False\
        if (len(st) == 0):\
            return True\
        else:\
            return False\
    \
    def isOpening(self, ch):\
        return ch == '(' or ch == '\{' or ch == '['\
\
    def doesMatch(self, och, cch):\
        return (och == '(' and cch == ')') or (och == '\{' and cch == '\}') or (och == '[' and cch == ']')}
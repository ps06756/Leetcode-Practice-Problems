{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def findJudge(self, n: int, trust: List[List[int]]) -> int:\
        if n==1 : return 1\
        indeg= collections.defaultdict(int)\
        outdeg= collections.defaultdict(int)\
        print(indeg, outdeg)\
        \
        for a,b in trust:\
            outdeg[a]+=1\
            indeg[b]+=1\
        print(indeg, outdeg)\
        \
        for key,val in indeg.items():\
            if val==n-1 and outdeg[key]==0: return key\
        \
        return -1\
                }
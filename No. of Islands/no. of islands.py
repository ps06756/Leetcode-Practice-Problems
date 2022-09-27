{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def numIslands(self, grid: List[List[str]]) -> int:\
        self.grid = grid\
        count = 0\
        for row in range(0, len(grid)):\
            for col in range(0, len(grid[0])):\
                if (grid[row][col] == '1'):\
                    count += 1\
                    self.dfs(row, col)\
        return count\
    \
    def dfs(self, row, col):\
        if (self.isValid(row, col)):\
            self.grid[row][col] = '2'\
            self.dfs(row - 1, col)\
            self.dfs(row + 1, col)\
            self.dfs(row, col - 1)\
            self.dfs(row, col + 1)\
    \
    def isValid(self, row, col):\
        if (row < 0 or row >= len(self.grid)):\
            return False\
        if (col < 0 or col >= len(self.grid[0])):\
            return False\
        \
        if self.grid[row][col] == '1':\
            return True\
        return False}
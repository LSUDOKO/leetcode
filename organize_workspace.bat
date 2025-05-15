@echo off
REM Script to organize LeetCode solutions by language and topic
cd "%~dp0\leetcode"

echo Creating directory structure...

REM Create language folders if they don't exist
if not exist cpp mkdir cpp
if not exist python mkdir python
if not exist sql mkdir sql
if not exist js mkdir js

REM Create category folders within cpp
if not exist cpp\array mkdir cpp\array
if not exist cpp\binary-search mkdir cpp\binary-search 
if not exist cpp\dp mkdir cpp\dp
if not exist cpp\sorting mkdir cpp\sorting
if not exist cpp\string mkdir cpp\string
if not exist cpp\linkedlist mkdir cpp\linkedlist
if not exist cpp\tree mkdir cpp\tree
if not exist cpp\graph mkdir cpp\graph

REM Move C++ files by known topics (examples)
echo Moving C++ files into topic folders...

REM Binary Search related files
move /Y *binary*search*.cpp cpp\binary-search\ >nul 2>&1
move /Y *search*.cpp cpp\binary-search\ >nul 2>&1
move /Y 33_search_in_rotated_sorted_array.cpp cpp\binary-search\ >nul 2>&1
move /Y 34*.cpp cpp\binary-search\ >nul 2>&1
move /Y 35*.cpp cpp\binary-search\ >nul 2>&1
move /Y 69*.cpp cpp\binary-search\ >nul 2>&1
move /Y 704*.cpp cpp\binary-search\ >nul 2>&1
move /Y 81*.cpp cpp\binary-search\ >nul 2>&1
move /Y 153*.cpp cpp\binary-search\ >nul 2>&1
move /Y 162*.cpp cpp\binary-search\ >nul 2>&1
move /Y 540*.cpp cpp\binary-search\ >nul 2>&1

REM Array related
move /Y *array*.cpp cpp\array\ >nul 2>&1
move /Y 1*.cpp cpp\array\ >nul 2>&1
move /Y 15*.cpp cpp\array\ >nul 2>&1
move /Y 18*.cpp cpp\array\ >nul 2>&1
move /Y 26*.cpp cpp\array\ >nul 2>&1
move /Y 39*.cpp cpp\array\ >nul 2>&1
move /Y 48*.cpp cpp\array\ >nul 2>&1
move /Y 53*.cpp cpp\array\ >nul 2>&1
move /Y 54*.cpp cpp\array\ >nul 2>&1
move /Y 56*.cpp cpp\array\ >nul 2>&1
move /Y 75*.cpp cpp\array\ >nul 2>&1
move /Y 88*.cpp cpp\array\ >nul 2>&1
move /Y 118*.cpp cpp\array\ >nul 2>&1
move /Y 119*.cpp cpp\array\ >nul 2>&1
move /Y 121*.cpp cpp\array\ >nul 2>&1
move /Y 128*.cpp cpp\array\ >nul 2>&1
move /Y 169*.cpp cpp\array\ >nul 2>&1
move /Y 189*.cpp cpp\array\ >nul 2>&1
move /Y 229*.cpp cpp\array\ >nul 2>&1
move /Y 268*.cpp cpp\array\ >nul 2>&1
move /Y 283*.cpp cpp\array\ >nul 2>&1
move /Y 349*.cpp cpp\array\ >nul 2>&1
move /Y 350*.cpp cpp\array\ >nul 2>&1
move /Y 485*.cpp cpp\array\ >nul 2>&1
move /Y 560*.cpp cpp\array\ >nul 2>&1
move /Y 1752*.cpp cpp\array\ >nul 2>&1
move /Y 1929*.cpp cpp\array\ >nul 2>&1
move /Y 1979*.cpp cpp\array\ >nul 2>&1
move /Y 2149*.cpp cpp\array\ >nul 2>&1

REM DP related
move /Y 152*.cpp cpp\dp\ >nul 2>&1
move /Y 131*.cpp cpp\dp\ >nul 2>&1
move /Y 509*.cpp cpp\dp\ >nul 2>&1

REM Sorting
move /Y *sort*.cpp cpp\sorting\ >nul 2>&1
move /Y 912*.cpp cpp\sorting\ >nul 2>&1

REM String related
move /Y *palindrome*.cpp cpp\string\ >nul 2>&1
move /Y 7*.cpp cpp\string\ >nul 2>&1
move /Y 9*.cpp cpp\string\ >nul 2>&1
move /Y 125*.cpp cpp\string\ >nul 2>&1

REM Default move for remaining files
move /Y *.cpp cpp\ >nul 2>&1
move /Y *.py python\ >nul 2>&1
move /Y *.sql sql\ >nul 2>&1
move /Y *.js js\ >nul 2>&1

echo Workspace organized by language and topic!
echo.
echo ✅ C++ files sorted into topics (array, binary-search, dp, etc.)
echo ✅ Python, SQL, and JavaScript files moved to their folders
pause

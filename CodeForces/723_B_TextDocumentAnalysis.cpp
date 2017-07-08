#include<bits/stdc++.h>
using namespace std;

int n;
char kal[300];

bool isLetter(char a) {
  if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) return true;
  return false;
}

int main() {

  scanf("%d",&n);
  for (int i=0; i<=n; i++) {
    scanf("%c",&kal[i]);
  }
  kal[n+1] = '_';

  bool isWord = true;
  bool inParenthesis = false;
  int tempLength = 0;
  int maxLength = 0;
  int wordCount = 0;

  for (int i=0; i<=n+1; i++) {
    if (inParenthesis) {
      if (isLetter(kal[i])) {
        isWord = true;
      } else {
        if (isWord) {
          wordCount++;
        }
        isWord = false;
        if (kal[i] == ')') {
          inParenthesis = false;
        }
      }
    } else {
      if (isLetter(kal[i])) {
        if (isWord) {
          tempLength++;
        } else {
          isWord = true;
          tempLength = 1;
        }
      } else {
        if (isWord) {
          maxLength = max(maxLength,tempLength);
        }
        tempLength = 0;
        isWord = false;
        if (kal[i] == '(') {
          inParenthesis = true;
        }
      }
    }
  }

  printf("%d %d\n",maxLength,wordCount);
}

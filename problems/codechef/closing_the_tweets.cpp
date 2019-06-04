/*
* Closing the Tweets
* https://www.codechef.com/problems/TWTCLOSE
*/

#define MAX 1005
#include <iostream>

using namespace std;

bool TWEETS[MAX];
int N, K, open, tweet;
string cmd;

void closeAll() {
  open = 0;
  for (int i = 1; i <= N; i++) {
    TWEETS[i] = false;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);

  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> cmd;
    if (cmd == "CLICK") {
      cin >> tweet;
      TWEETS[tweet] = !TWEETS[tweet];
      open += TWEETS[tweet];
      open -= !TWEETS[tweet];
    } else {
      closeAll();
    }

    cout << open << endl;
  }
}

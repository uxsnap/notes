#include <set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if(n == 0) return 0;
    set<char> st;
    int maxsize = 0, p1 = 0, p2 = 0;
    while(p2 < n)
    {   
        /* Check if element is in set */
        if(st.count(s[p2]) == 0)
        {
            /* If not - insert it and change maxsize if needed */
            st.insert(s[p2]);
            maxsize = max(maxsize, (int)st.size());
            /* Increment second pointer*/
            p2++;
        }
        else
        {
            /* If element is in set, delete it */
            st.erase(s[p1]);
            /* And increment first pointer */
            p1++;
        }
    }
    return maxsize;
}
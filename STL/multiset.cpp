#include<bits/stdc++.h>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<set>

using namespace std;

int main()
{
    int a[81] = {1,4,7,7,7,8,9,7};
    multiset<int>ms(a,a+8);
    multiset<int>:: iterator it;
    it = ms.lower_bound(7); /** to erase only one element from same multiple element */
    ms.erase(it);
    cout<<ms.count(7)<<"   line 16"; /** erased only one 7 */

    ms.erase(7); /** erased all 7 */
    ms.insert(7);
    cout<<ms.count(7)<<"   line 20\n";

    long long int n = 2e17;

    cout<<n%3<<" "<<"line 24\n"; /** if long long works with % ,,,, yes */


    char s[25] = "15245254587444";

    cout<<atoi(s)%5<<"  line 28\n"; /*** output -1,... don't work with long long  */

    char x[25]="987654";
    cout<<atoll(x)%5<<"   line 32\n"; /** 4 output */

    it = ms.lower_bound(atoi(x));

    cout<<*it;







    return 0 ;
}

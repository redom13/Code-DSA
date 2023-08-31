#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define p pair<int, int>
#define vp vector<p>
#define f first
#define s second
#define FOR(i, n) for (int i = 0; i < n; i++)

float Y(p a, p b, float x)
{
    //cout<<"Y for ("<<a.f<<" "<<a.s<<") & ("<<b.f<<" "<<b.s<<"): "<<(x - a.f) * (a.s - b.s) / (float)(a.f - b.f) + (float)a.s<<endl;
    return (x - a.f) * (a.s - b.s) / (float)(a.f - b.f) + (float)a.s;
}

int dcr(int i, int size)
{
    //cout<<"dcr: "<<((i - 1) % size + size) % size<<endl;
    return ((i - 1) % size + size) % size;
}
/**  FOR BASE CASE  **/
vp brute(vp &v, int start, int end)
{
    // Assuming the points are already sorted based on x coord
    vp res;
    res.pb(v[end]);
    if (end - start == 1)
    {
        res.pb(v[start]);
        return res;
    }
    if (v[start].s < v[start + 1].s)
    {
        res.pb(v[start]);
        res.pb(v[start + 1]);
    }
    else
    {
        res.pb(v[start + 1]);
        res.pb(v[start]);
    }
    return res;
}

vp leftOrder(vp a)
{
    int i;
    int mx = INT_MIN;
    int indx = -1;
    vp res;
    FOR(i, a.size())
    {
        if (a[i].f > mx)
        {
            mx = a[i].f;
            indx = i;
        }
    }
    FOR(i, a.size())
    {
        res.pb(a[(i + indx) % a.size()]);
    }
    return res;
}

vp rightOrder(vp a)
{
    int i;
    int mn = INT_MAX;
    int indx = -1;
    vp res;
    FOR(i, a.size())
    {
        if (a[i].f < mn)
        {
            mn = a[i].f;
            indx = i;
        }
    }
    FOR(i, a.size())
    {
        res.pb(a[(i + indx) % a.size()]);
    }
    return res;
}

// Returns the indices i,j such that a[i]b[j] is the tangent
p upperTangent(vp a, vp b, float x)
{
    int i = 0, j = 0;
    int la = a.size(), lb = b.size();
    //cout<<"For upper: "<<endl;
    while (Y(a[i], b[(j + 1) % lb], x) > Y(a[i], b[j], x) || Y(a[dcr(i, la)], b[j], x) > Y(a[i], b[j], x))
    {
        if (Y(a[i], b[(j + 1) % lb], x) > Y(a[i], b[j], x))
            j = (j + 1) % lb;
        else
            i = dcr(i, la);
    }
    //cout<<"(i,j):"<<i<<" "<<j<<endl;
    return {i, j};
}

p lowerTangent(vp a, vp b, float x)
{
    int i = 0, j = 0;
    int la = a.size(), lb = b.size();
    //cout<<"For lower: "<<endl;
    while (Y(a[(i + 1) % la], b[j], x) < Y(a[i], b[j], x) || Y(a[i], b[dcr(j, lb)], x) < Y(a[i], b[j], x))
    {
        // The Y intercept is smaller either for a or for b
        if (Y(a[(i + 1) % la], b[j], x) < Y(a[i], b[j], x))
            i = (i + 1) % la;
             // If a is responsible
        else
            j = dcr(j, lb); // Otherwise definitely b is responsible
    }
    //cout<<"(i,j):"<<i<<" "<<j<<endl;
    return {i, j};
}

/**           MERGING FUNCTION           **/
vp combine(vp a, vp b)
{
    a = leftOrder(a);
    b = rightOrder(b);
    float x = (a[0].f+b[0].f)/2.0;
    //cout<<"x: "<<x<<endl;
    p utInd = upperTangent(a, b, x), ltInd = lowerTangent(a, b, x); // Indices of tangents
    vp res;
    res.pb(a[utInd.f]);
    for (int i = utInd.s; i != ltInd.s; i = (i + 1) % b.size())
    {
        res.pb(b[i]);
    }
    res.pb(b[ltInd.s]);
    for (int i = ltInd.f; i != utInd.f; i = (i + 1) % a.size())
    {
        res.pb(a[i]);
    }
    return res;
}

/**                 RECURSIVE FUNCTION               **/
vp fench(vp &v, int start, int end)
{
    int mid = (start + end) / 2;
    if (end - start <= 2)
        return brute(v, start, end); // Base case
    return combine(fench(v, start, mid), fench(v, mid + 1, end));
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("myOut.txt","w",stdout);
    int n;
    cin >> n;
    vp v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].f >> v[i].s;
    }
    sort(v.begin(), v.end()); // Sorted based on X coord
    vp ans = fench(v, 0, n-1);
    for (auto points : ans)
        cout << points.f << " " << points.s << endl;
}
#define EPS 1e-9 // this value is adjustable; 1e-9 is usually small enough
bool can(double f) { // details of this simulation is omitted
// return true if the jeep can reach goal state with fuel tank capacity f
// return false otherwise
}
// inside int main()
// binary search the answer, then simulate
double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
while (fabs(hi - lo) > EPS) { // when the answer is not found yet
    mid = (lo + hi) / 2.0; // try the middle value
    if (can(mid)) { ans = mid; hi = mid; } // save the value, then continue
    else lo = mid;
}
printf("%.3lf\n", ans); // after the loop is over, we have the answer

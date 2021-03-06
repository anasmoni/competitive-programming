/**
    solutions for xA + yB = C
    see cp algorithm "Linear Diophantine Equation"
*/

lli gcd(lli a, lli b, lli &x, lli &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    lli x1, y1;
    assert(a>0);
    lli d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(lli a, lli b, lli c, lli &x0, lli &y0, lli &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(lli & x, lli & y, lli a, lli b, lli cnt) {
    x += cnt * b;
    y -= cnt * a;
}

lli find_all_solutions(lli a, lli b, lli c, lli minx, lli maxx, lli miny, lli maxy) {
    lli x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;

    assert(g>0);
    a /= g;
    b /= g;

    lli sign_a = a > 0 ? +1 : -1;
    lli sign_b = b > 0 ? +1 : -1;

    assert(b>0);

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    lli lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    lli rx1 = x;
    assert(a>0);
    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    lli lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    lli rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    lli lx = max(lx1, lx2);
    lli rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}


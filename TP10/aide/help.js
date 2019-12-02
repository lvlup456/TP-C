function go() {
    for (k = 0; k <= 2; k++) {
        x[k] = 0
    };
    with(Math) {
        a = prompt("a = ", a)
        if (a == null) {
            return
        } else {
            a = eval(a)
        }
        if (a == 0) {
            alert("a ne peut pas être nul !");
            return
        }
        b = prompt("b = ", b)
        if (b == null) {
            return
        } else {
            b = eval(b)
        }
        c = prompt("c = ", c)
        if (c == null) {
            return
        } else {
            c = eval(c)
        }
        d = prompt("d = ", d)
        if (d == null) {
            return
        } else {
            d = eval(d)
        }
        vt = -b / 3 / a;
        mvt = -vt;
        p = c / a - b * b / 3 / a / a;
        q = b * b * b / a / a / a / 13.5 + d / a - b * c / 3 / a / a;
        if (abs(p) < 1e-14) {
            p = 0
        };
        if (abs(q) < 1e-14) {
            q = 0
        };
        del = q * q / 4 + p * p * p / 27;
        if (abs(del) < 1e-14) {
            del = 0
        }
        alert("Forme X^3 + pX + q avec x = X - b/3a" + "\n" + "b/3a = " + mvt + "\n" + "p = " + p + " ; q = " + q + "\n" + "delta = " + del)
        // -------------------------------------------
        if (del <= 0) {
            if (p != 0) {
                kos = -q / 2 / sqrt(-p * p * p / 27);
                r = sqrt(-p / 3)
            } else {
                kos = 0;
                r = 0
            } // vu que del<=0, si p=0, alors del=0
            if (abs(abs(kos) - 1) < 1e-14) {
                alpha = -pi * (kos - 1) / 2
            } else {
                alpha = acos(kos)
            }
            for (k = 0; k <= 2; k++) {
                xk = 2 * r * cos((alpha + 2 * k * pi) / 3) + vt;
                x[k] = arrondi(xk)
            }
            if (r == 0) {
                triple = "Solution triple :"
            } else {
                triple = "Trois solutions :"
            }
            alert(triple + "\n" + "x1=" + x[0] + "\n" + "x2=" + x[1] + "\n" + "x3=" + x[2])
        }
        // ----------- fin if
        else {
            xuni = arrondi(uv(1) + uv(-1) + vt);
            alert("x unique, x = " + xuni)
        } // fin else
    } // fin with
} // fin procedure

// ----------------------------

function uv(sg) {
    with(Math) {
        r = sqrt(del);
        z = -q / 2 + sg * r;
        return sgn(z) * pow(abs(z), 1 / 3)
    }
}

function sgn(x) {
    s = (x > 0) - (x < 0);
    return s
}

function arrondi(x) {
    return sgn(x) * Math.floor(Math.abs(x) * 1e10 + .5) / 1e10
}

function list2() {
    open("listing_equ3.html", "")
}
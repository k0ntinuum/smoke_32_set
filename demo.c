
void demo() {
    unt f = 0,  fail = 0, enc_row = 8 , marg = 4, page_delay = 1000000, row_delay = 100000;
    cls();hide_cursor();
    for (size_t t = 0; t < 200000; t++) {
        cls();
        cursor_to(3,0);
        if (t %5 == 0 ) {
            srand(time(NULL));
            //vary system parameters for demo
            P = 1 << (2 + arc4random_uniform(2));
            S = L / P;
            E = 1 + arc4random_uniform(4);
            f = balanced_f();
        }
        unt p = first_P_bits(arc4random());
        unt c = enc(f, p);
        unt d = dec(f, c);
        
        spaces(marg);printf(" f  =  ");print_bits(f);nl();
        spaces(marg);printf(" p  =  ");print_p(p);nl();
        spaces(marg);printf(" c  =  ");print_bits(c);
        cursor_to(enc_row + E,0);
        spaces(marg);printf(" d  =  ");print_p(d);
        cursor_to(enc_row ,0);
        for (unt e = 0; e < E; e++ ) {
            c = ca(f, c);
            usleep(row_delay);
            spaces(marg+ 7);;print_c_highlights(c);
        }
        //if (d != p) fail++;
        //printf("\nERRORS %d", fail); 
        usleep(page_delay);

    }

}
void demo_set() {
    unt f_set[10] = {0},  down = 4, fail = 0, enc_row, marg = 4, page_delay = 500000, row_delay = 100000;
    cls();hide_cursor();
    for (size_t t = 0; t < 200000; t++) {
        cls();
        cursor_to(down,0);
        if (t % 2 == 0 ) {
            srand(time(NULL));
            //vary system parameters for demo
            P = 1 << (2 + arc4random_uniform(2));
            S = L / P;
            E = 1 + arc4random_uniform(4);
            enc_row = down + E + 1;
            init_f_set(f_set);
        }
        unt p = first_P_bits(arc4random());
        unt c = enc_set(f_set, p);
        unt d = dec_set(f_set, c);
        
        spaces(marg);printf(" f  =  ");print_bits(f_set[0]);
        for (unt e = 1; e < E; e++ ) {spaces(marg + 7);print_bits(f_set[e]);}
        nl();
        //spaces(marg);printf(" p  =  ");print_p(p);nl();
        cursor_to(enc_row ,0);
        spaces(marg);printf(" c  =  ");print_bits(c);
        cursor_to(enc_row + E + 1,0);
        spaces(marg);printf(" p  =  ");print_p(d);
        cursor_to(enc_row + 1,0);
        for (unt e = 0; e < E; e++ ) {
            c = ca(f_set[e], c);
            usleep(row_delay);
            spaces(marg+ 7);;print_c_highlights(c);
        }
        //if (d != p) fail++;
        //printf("\nERRORS %d", fail); 
        usleep(page_delay);

    }

}

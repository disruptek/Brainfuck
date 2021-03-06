#if !defined(DISABLE_GMP)

#ifndef _BFI_GMP_H
#define _BFI_GMP_H

void run_gmparray(void);
#endif

#ifdef XX
X(gmp,LIBGMP,
    printf("   -fgmp Run using libgmp bignums\n");			,
    /* No short option */						,
    /* No code dump */							,
    case c_gmp: run_gmparray(); break;                           )
#if XX == 4
    if (do_run == -1 && do_codestyle == c_default &&
            (cell_length > 128 ||(cell_length>32 && iostyle == 3)) &&
            verbose<3 && !enable_trace && !debug_mode) {
        do_run = 1;
        do_codestyle = c_gmp;
    }
    if (do_codestyle == c_gmp && do_run == -1) do_run = 1;
#endif
#if XX == 9
    if (!strcmp(opt, "-fgmp")) {
	do_codestyle = c_gmp;
	return 1;
    }
#endif
#endif

#endif

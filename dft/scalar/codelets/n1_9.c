/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu Dec 10 07:04:08 EST 2020 */

#include "codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw.native -fma -compact -variables 4 -pipeline-latency 4 -n 9 -name n1_9 -include n.h */

/*
 * This function contains 80 FP additions, 56 FP multiplications,
 * (or, 24 additions, 0 multiplications, 56 fused multiply/add),
 * 41 stack variables, 10 constants, and 36 memory accesses
 */
#include "n.h"

static void n1_9(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DK(KP954188894, +0.954188894138671133499268364187245676532219158);
     DK(KP363970234, +0.363970234266202361351047882776834043890471784);
     DK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DK(KP492403876, +0.492403876506104029683371512294761506835321626);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP777861913, +0.777861913430206160028177977318626690410586096);
     DK(KP839099631, +0.839099631177280011763127298123181364687434283);
     DK(KP176326980, +0.176326980708464973471090386868618986121633062);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(36, is), MAKE_VOLATILE_STRIDE(36, os)) {
	       E T5, TL, Tm, Tl, T1f, TM, Ta, T1c, TF, TW, TI, TX, Tf, T1d, Ts;
	       E TZ, Tx, T10;
	       {
		    E T1, T2, T3, T4;
		    T1 = ri[0];
		    T2 = ri[WS(is, 3)];
		    T3 = ri[WS(is, 6)];
		    T4 = T2 + T3;
		    T5 = T1 + T4;
		    TL = FNMS(KP500000000, T4, T1);
		    Tm = T3 - T2;
	       }
	       {
		    E Th, Ti, Tj, Tk;
		    Th = ii[0];
		    Ti = ii[WS(is, 3)];
		    Tj = ii[WS(is, 6)];
		    Tk = Ti + Tj;
		    Tl = FNMS(KP500000000, Tk, Th);
		    T1f = Th + Tk;
		    TM = Ti - Tj;
	       }
	       {
		    E T6, Tz, T9, TE, TC, TH, TD, TG;
		    T6 = ri[WS(is, 1)];
		    Tz = ii[WS(is, 1)];
		    {
			 E T7, T8, TA, TB;
			 T7 = ri[WS(is, 4)];
			 T8 = ri[WS(is, 7)];
			 T9 = T7 + T8;
			 TE = T7 - T8;
			 TA = ii[WS(is, 4)];
			 TB = ii[WS(is, 7)];
			 TC = TA + TB;
			 TH = TB - TA;
		    }
		    Ta = T6 + T9;
		    T1c = Tz + TC;
		    TD = FNMS(KP500000000, TC, Tz);
		    TF = FNMS(KP866025403, TE, TD);
		    TW = FMA(KP866025403, TE, TD);
		    TG = FNMS(KP500000000, T9, T6);
		    TI = FNMS(KP866025403, TH, TG);
		    TX = FMA(KP866025403, TH, TG);
	       }
	       {
		    E Tb, Tt, Te, Tw, Tr, Tu, To, Tv;
		    Tb = ri[WS(is, 2)];
		    Tt = ii[WS(is, 2)];
		    {
			 E Tc, Td, Tp, Tq;
			 Tc = ri[WS(is, 5)];
			 Td = ri[WS(is, 8)];
			 Te = Tc + Td;
			 Tw = Td - Tc;
			 Tp = ii[WS(is, 5)];
			 Tq = ii[WS(is, 8)];
			 Tr = Tp - Tq;
			 Tu = Tp + Tq;
		    }
		    Tf = Tb + Te;
		    T1d = Tt + Tu;
		    To = FNMS(KP500000000, Te, Tb);
		    Ts = FMA(KP866025403, Tr, To);
		    TZ = FNMS(KP866025403, Tr, To);
		    Tv = FNMS(KP500000000, Tu, Tt);
		    Tx = FMA(KP866025403, Tw, Tv);
		    T10 = FNMS(KP866025403, Tw, Tv);
	       }
	       {
		    E T1e, Tg, T1b, T1i, T1g, T1h;
		    T1e = T1c - T1d;
		    Tg = Ta + Tf;
		    T1b = FNMS(KP500000000, Tg, T5);
		    ro[0] = T5 + Tg;
		    ro[WS(os, 3)] = FMA(KP866025403, T1e, T1b);
		    ro[WS(os, 6)] = FNMS(KP866025403, T1e, T1b);
		    T1i = Tf - Ta;
		    T1g = T1c + T1d;
		    T1h = FNMS(KP500000000, T1g, T1f);
		    io[WS(os, 3)] = FMA(KP866025403, T1i, T1h);
		    io[0] = T1f + T1g;
		    io[WS(os, 6)] = FNMS(KP866025403, T1i, T1h);
	       }
	       {
		    E Tn, TN, TK, TS, TQ, TU, TR, TT;
		    Tn = FMA(KP866025403, Tm, Tl);
		    TN = FMA(KP866025403, TM, TL);
		    {
			 E Ty, TJ, TO, TP;
			 Ty = FNMS(KP176326980, Tx, Ts);
			 TJ = FNMS(KP839099631, TI, TF);
			 TK = FNMS(KP777861913, TJ, Ty);
			 TS = FMA(KP777861913, TJ, Ty);
			 TO = FMA(KP176326980, Ts, Tx);
			 TP = FMA(KP839099631, TF, TI);
			 TQ = FMA(KP777861913, TP, TO);
			 TU = FNMS(KP777861913, TP, TO);
		    }
		    io[WS(os, 1)] = FNMS(KP984807753, TK, Tn);
		    ro[WS(os, 1)] = FMA(KP984807753, TQ, TN);
		    TR = FNMS(KP492403876, TQ, TN);
		    ro[WS(os, 4)] = FMA(KP852868531, TS, TR);
		    ro[WS(os, 7)] = FNMS(KP852868531, TS, TR);
		    TT = FMA(KP492403876, TK, Tn);
		    io[WS(os, 7)] = FNMS(KP852868531, TU, TT);
		    io[WS(os, 4)] = FMA(KP852868531, TU, TT);
	       }
	       {
		    E TV, T17, T12, T1a, T16, T18, T13, T19;
		    TV = FNMS(KP866025403, TM, TL);
		    T17 = FNMS(KP866025403, Tm, Tl);
		    {
			 E TY, T11, T14, T15;
			 TY = FMA(KP176326980, TX, TW);
			 T11 = FNMS(KP363970234, T10, TZ);
			 T12 = FNMS(KP954188894, T11, TY);
			 T1a = FMA(KP954188894, T11, TY);
			 T14 = FNMS(KP176326980, TW, TX);
			 T15 = FMA(KP363970234, TZ, T10);
			 T16 = FNMS(KP954188894, T15, T14);
			 T18 = FMA(KP954188894, T15, T14);
		    }
		    ro[WS(os, 2)] = FMA(KP984807753, T12, TV);
		    io[WS(os, 2)] = FNMS(KP984807753, T18, T17);
		    T13 = FNMS(KP492403876, T12, TV);
		    ro[WS(os, 5)] = FNMS(KP852868531, T16, T13);
		    ro[WS(os, 8)] = FMA(KP852868531, T16, T13);
		    T19 = FMA(KP492403876, T18, T17);
		    io[WS(os, 5)] = FNMS(KP852868531, T1a, T19);
		    io[WS(os, 8)] = FMA(KP852868531, T1a, T19);
	       }
	  }
     }
}

static const kdft_desc desc = { 9, "n1_9", { 24, 0, 56, 0 }, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_9) (planner *p) { X(kdft_register) (p, n1_9, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw.native -compact -variables 4 -pipeline-latency 4 -n 9 -name n1_9 -include n.h */

/*
 * This function contains 80 FP additions, 40 FP multiplications,
 * (or, 60 additions, 20 multiplications, 20 fused multiply/add),
 * 39 stack variables, 8 constants, and 36 memory accesses
 */
#include "n.h"

static void n1_9(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(36, is), MAKE_VOLATILE_STRIDE(36, os)) {
	       E T5, TO, Th, Tk, T1g, TR, Ta, T1c, Tq, TW, Tv, TX, Tf, T1d, TB;
	       E T10, TG, TZ;
	       {
		    E T1, T2, T3, T4;
		    T1 = ri[0];
		    T2 = ri[WS(is, 3)];
		    T3 = ri[WS(is, 6)];
		    T4 = T2 + T3;
		    T5 = T1 + T4;
		    TO = KP866025403 * (T3 - T2);
		    Th = FNMS(KP500000000, T4, T1);
	       }
	       {
		    E TP, Ti, Tj, TQ;
		    TP = ii[0];
		    Ti = ii[WS(is, 3)];
		    Tj = ii[WS(is, 6)];
		    TQ = Ti + Tj;
		    Tk = KP866025403 * (Ti - Tj);
		    T1g = TP + TQ;
		    TR = FNMS(KP500000000, TQ, TP);
	       }
	       {
		    E T6, Ts, T9, Tr, Tp, Tt, Tm, Tu;
		    T6 = ri[WS(is, 1)];
		    Ts = ii[WS(is, 1)];
		    {
			 E T7, T8, Tn, To;
			 T7 = ri[WS(is, 4)];
			 T8 = ri[WS(is, 7)];
			 T9 = T7 + T8;
			 Tr = KP866025403 * (T8 - T7);
			 Tn = ii[WS(is, 4)];
			 To = ii[WS(is, 7)];
			 Tp = KP866025403 * (Tn - To);
			 Tt = Tn + To;
		    }
		    Ta = T6 + T9;
		    T1c = Ts + Tt;
		    Tm = FNMS(KP500000000, T9, T6);
		    Tq = Tm + Tp;
		    TW = Tm - Tp;
		    Tu = FNMS(KP500000000, Tt, Ts);
		    Tv = Tr + Tu;
		    TX = Tu - Tr;
	       }
	       {
		    E Tb, TD, Te, TC, TA, TE, Tx, TF;
		    Tb = ri[WS(is, 2)];
		    TD = ii[WS(is, 2)];
		    {
			 E Tc, Td, Ty, Tz;
			 Tc = ri[WS(is, 5)];
			 Td = ri[WS(is, 8)];
			 Te = Tc + Td;
			 TC = KP866025403 * (Td - Tc);
			 Ty = ii[WS(is, 5)];
			 Tz = ii[WS(is, 8)];
			 TA = KP866025403 * (Ty - Tz);
			 TE = Ty + Tz;
		    }
		    Tf = Tb + Te;
		    T1d = TD + TE;
		    Tx = FNMS(KP500000000, Te, Tb);
		    TB = Tx + TA;
		    T10 = Tx - TA;
		    TF = FNMS(KP500000000, TE, TD);
		    TG = TC + TF;
		    TZ = TF - TC;
	       }
	       {
		    E T1e, Tg, T1b, T1f, T1h, T1i;
		    T1e = KP866025403 * (T1c - T1d);
		    Tg = Ta + Tf;
		    T1b = FNMS(KP500000000, Tg, T5);
		    ro[0] = T5 + Tg;
		    ro[WS(os, 3)] = T1b + T1e;
		    ro[WS(os, 6)] = T1b - T1e;
		    T1f = KP866025403 * (Tf - Ta);
		    T1h = T1c + T1d;
		    T1i = FNMS(KP500000000, T1h, T1g);
		    io[WS(os, 3)] = T1f + T1i;
		    io[0] = T1g + T1h;
		    io[WS(os, 6)] = T1i - T1f;
	       }
	       {
		    E Tl, TS, TI, TN, TM, TT, TJ, TU;
		    Tl = Th + Tk;
		    TS = TO + TR;
		    {
			 E Tw, TH, TK, TL;
			 Tw = FMA(KP766044443, Tq, KP642787609 * Tv);
			 TH = FMA(KP173648177, TB, KP984807753 * TG);
			 TI = Tw + TH;
			 TN = KP866025403 * (TH - Tw);
			 TK = FNMS(KP642787609, Tq, KP766044443 * Tv);
			 TL = FNMS(KP984807753, TB, KP173648177 * TG);
			 TM = KP866025403 * (TK - TL);
			 TT = TK + TL;
		    }
		    ro[WS(os, 1)] = Tl + TI;
		    io[WS(os, 1)] = TS + TT;
		    TJ = FNMS(KP500000000, TI, Tl);
		    ro[WS(os, 7)] = TJ - TM;
		    ro[WS(os, 4)] = TJ + TM;
		    TU = FNMS(KP500000000, TT, TS);
		    io[WS(os, 4)] = TN + TU;
		    io[WS(os, 7)] = TU - TN;
	       }
	       {
		    E TV, T14, T12, T13, T17, T1a, T18, T19;
		    TV = Th - Tk;
		    T14 = TR - TO;
		    {
			 E TY, T11, T15, T16;
			 TY = FMA(KP173648177, TW, KP984807753 * TX);
			 T11 = FNMS(KP939692620, T10, KP342020143 * TZ);
			 T12 = TY + T11;
			 T13 = KP866025403 * (T11 - TY);
			 T15 = FNMS(KP984807753, TW, KP173648177 * TX);
			 T16 = FMA(KP342020143, T10, KP939692620 * TZ);
			 T17 = T15 - T16;
			 T1a = KP866025403 * (T15 + T16);
		    }
		    ro[WS(os, 2)] = TV + T12;
		    io[WS(os, 2)] = T14 + T17;
		    T18 = FNMS(KP500000000, T17, T14);
		    io[WS(os, 5)] = T13 + T18;
		    io[WS(os, 8)] = T18 - T13;
		    T19 = FNMS(KP500000000, T12, TV);
		    ro[WS(os, 8)] = T19 - T1a;
		    ro[WS(os, 5)] = T19 + T1a;
	       }
	  }
     }
}

static const kdft_desc desc = { 9, "n1_9", { 60, 20, 20, 0 }, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_9) (planner *p) { X(kdft_register) (p, n1_9, &desc);
}

#endif
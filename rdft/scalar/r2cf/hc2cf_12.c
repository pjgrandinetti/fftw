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
/* Generated on Thu Dec 10 07:06:09 EST 2020 */

#include "codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4 -pipeline-latency 4 -n 12 -dit -name hc2cf_12 -include hc2cf.h */

/*
 * This function contains 118 FP additions, 68 FP multiplications,
 * (or, 72 additions, 22 multiplications, 46 fused multiply/add),
 * 47 stack variables, 2 constants, and 48 memory accesses
 */
#include "hc2cf.h"

static void hc2cf_12(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 22); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 22, MAKE_VOLATILE_STRIDE(48, rs)) {
	       E T1, T2i, Tl, T2e, T10, T1Y, TG, T1S, Ty, T2s, T1s, T2f, T1d, T21, T1H;
	       E T1Z, Te, T2p, T1l, T2h, TT, T1V, T1A, T1T;
	       T1 = Rp[0];
	       T2i = Rm[0];
	       {
		    E Th, Tk, Ti, T2d, Tg, Tj;
		    Th = Rp[WS(rs, 3)];
		    Tk = Rm[WS(rs, 3)];
		    Tg = W[10];
		    Ti = Tg * Th;
		    T2d = Tg * Tk;
		    Tj = W[11];
		    Tl = FMA(Tj, Tk, Ti);
		    T2e = FNMS(Tj, Th, T2d);
	       }
	       {
		    E TW, TZ, TX, T1X, TV, TY;
		    TW = Ip[WS(rs, 4)];
		    TZ = Im[WS(rs, 4)];
		    TV = W[16];
		    TX = TV * TW;
		    T1X = TV * TZ;
		    TY = W[17];
		    T10 = FMA(TY, TZ, TX);
		    T1Y = FNMS(TY, TW, T1X);
	       }
	       {
		    E TC, TF, TD, T1R, TB, TE;
		    TC = Ip[WS(rs, 1)];
		    TF = Im[WS(rs, 1)];
		    TB = W[4];
		    TD = TB * TC;
		    T1R = TB * TF;
		    TE = W[5];
		    TG = FMA(TE, TF, TD);
		    T1S = FNMS(TE, TC, T1R);
	       }
	       {
		    E Tn, Tq, To, T1o, Tt, Tw, Tu, T1q, Tm, Ts;
		    Tn = Rp[WS(rs, 5)];
		    Tq = Rm[WS(rs, 5)];
		    Tm = W[18];
		    To = Tm * Tn;
		    T1o = Tm * Tq;
		    Tt = Rp[WS(rs, 1)];
		    Tw = Rm[WS(rs, 1)];
		    Ts = W[2];
		    Tu = Ts * Tt;
		    T1q = Ts * Tw;
		    {
			 E Tr, T1p, Tx, T1r, Tp, Tv;
			 Tp = W[19];
			 Tr = FMA(Tp, Tq, To);
			 T1p = FNMS(Tp, Tn, T1o);
			 Tv = W[3];
			 Tx = FMA(Tv, Tw, Tu);
			 T1r = FNMS(Tv, Tt, T1q);
			 Ty = Tr + Tx;
			 T2s = Tx - Tr;
			 T1s = T1p - T1r;
			 T2f = T1p + T1r;
		    }
	       }
	       {
		    E T12, T15, T13, T1D, T18, T1b, T19, T1F, T11, T17;
		    T12 = Ip[0];
		    T15 = Im[0];
		    T11 = W[0];
		    T13 = T11 * T12;
		    T1D = T11 * T15;
		    T18 = Ip[WS(rs, 2)];
		    T1b = Im[WS(rs, 2)];
		    T17 = W[8];
		    T19 = T17 * T18;
		    T1F = T17 * T1b;
		    {
			 E T16, T1E, T1c, T1G, T14, T1a;
			 T14 = W[1];
			 T16 = FMA(T14, T15, T13);
			 T1E = FNMS(T14, T12, T1D);
			 T1a = W[9];
			 T1c = FMA(T1a, T1b, T19);
			 T1G = FNMS(T1a, T18, T1F);
			 T1d = T16 + T1c;
			 T21 = T1c - T16;
			 T1H = T1E - T1G;
			 T1Z = T1E + T1G;
		    }
	       }
	       {
		    E T3, T6, T4, T1h, T9, Tc, Ta, T1j, T2, T8;
		    T3 = Rp[WS(rs, 2)];
		    T6 = Rm[WS(rs, 2)];
		    T2 = W[6];
		    T4 = T2 * T3;
		    T1h = T2 * T6;
		    T9 = Rp[WS(rs, 4)];
		    Tc = Rm[WS(rs, 4)];
		    T8 = W[14];
		    Ta = T8 * T9;
		    T1j = T8 * Tc;
		    {
			 E T7, T1i, Td, T1k, T5, Tb;
			 T5 = W[7];
			 T7 = FMA(T5, T6, T4);
			 T1i = FNMS(T5, T3, T1h);
			 Tb = W[15];
			 Td = FMA(Tb, Tc, Ta);
			 T1k = FNMS(Tb, T9, T1j);
			 Te = T7 + Td;
			 T2p = Td - T7;
			 T1l = T1i - T1k;
			 T2h = T1i + T1k;
		    }
	       }
	       {
		    E TI, TL, TJ, T1w, TO, TR, TP, T1y, TH, TN;
		    TI = Ip[WS(rs, 3)];
		    TL = Im[WS(rs, 3)];
		    TH = W[12];
		    TJ = TH * TI;
		    T1w = TH * TL;
		    TO = Ip[WS(rs, 5)];
		    TR = Im[WS(rs, 5)];
		    TN = W[20];
		    TP = TN * TO;
		    T1y = TN * TR;
		    {
			 E TM, T1x, TS, T1z, TK, TQ;
			 TK = W[13];
			 TM = FMA(TK, TL, TJ);
			 T1x = FNMS(TK, TI, T1w);
			 TQ = W[21];
			 TS = FMA(TQ, TR, TP);
			 T1z = FNMS(TQ, TO, T1y);
			 TT = TM + TS;
			 T1V = TS - TM;
			 T1A = T1x - T1z;
			 T1T = T1x + T1z;
		    }
	       }
	       {
		    E TA, T28, T2k, T2m, T1f, T2l, T2b, T2c;
		    {
			 E Tf, Tz, T2g, T2j;
			 Tf = T1 + Te;
			 Tz = Tl + Ty;
			 TA = Tf + Tz;
			 T28 = Tf - Tz;
			 T2g = T2e + T2f;
			 T2j = T2h + T2i;
			 T2k = T2g + T2j;
			 T2m = T2j - T2g;
		    }
		    {
			 E TU, T1e, T29, T2a;
			 TU = TG + TT;
			 T1e = T10 + T1d;
			 T1f = TU + T1e;
			 T2l = TU - T1e;
			 T29 = T1S + T1T;
			 T2a = T1Y + T1Z;
			 T2b = T29 - T2a;
			 T2c = T29 + T2a;
		    }
		    Rm[WS(rs, 5)] = TA - T1f;
		    Im[WS(rs, 5)] = T2c - T2k;
		    Rp[0] = TA + T1f;
		    Ip[0] = T2c + T2k;
		    Rp[WS(rs, 3)] = T28 - T2b;
		    Ip[WS(rs, 3)] = T2l + T2m;
		    Rm[WS(rs, 2)] = T28 + T2b;
		    Im[WS(rs, 2)] = T2l - T2m;
	       }
	       {
		    E T1m, T1K, T2q, T2z, T2t, T2y, T1t, T1L, T1B, T1N, T1W, T25, T22, T26, T1I;
		    E T1O;
		    {
			 E T1g, T2o, T2r, T1n;
			 T1g = FNMS(KP500000000, Te, T1);
			 T1m = FNMS(KP866025403, T1l, T1g);
			 T1K = FMA(KP866025403, T1l, T1g);
			 T2o = FNMS(KP500000000, T2h, T2i);
			 T2q = FMA(KP866025403, T2p, T2o);
			 T2z = FNMS(KP866025403, T2p, T2o);
			 T2r = FNMS(KP500000000, T2f, T2e);
			 T2t = FMA(KP866025403, T2s, T2r);
			 T2y = FNMS(KP866025403, T2s, T2r);
			 T1n = FNMS(KP500000000, Ty, Tl);
			 T1t = FNMS(KP866025403, T1s, T1n);
			 T1L = FMA(KP866025403, T1s, T1n);
		    }
		    {
			 E T1v, T1U, T20, T1C;
			 T1v = FNMS(KP500000000, TT, TG);
			 T1B = FNMS(KP866025403, T1A, T1v);
			 T1N = FMA(KP866025403, T1A, T1v);
			 T1U = FNMS(KP500000000, T1T, T1S);
			 T1W = FNMS(KP866025403, T1V, T1U);
			 T25 = FMA(KP866025403, T1V, T1U);
			 T20 = FNMS(KP500000000, T1Z, T1Y);
			 T22 = FNMS(KP866025403, T21, T20);
			 T26 = FMA(KP866025403, T21, T20);
			 T1C = FNMS(KP500000000, T1d, T10);
			 T1I = FNMS(KP866025403, T1H, T1C);
			 T1O = FMA(KP866025403, T1H, T1C);
		    }
		    {
			 E T1u, T1J, T2x, T2A;
			 T1u = T1m + T1t;
			 T1J = T1B + T1I;
			 Rp[WS(rs, 2)] = T1u - T1J;
			 Rm[WS(rs, 3)] = T1u + T1J;
			 T2x = T1W + T22;
			 T2A = T2y + T2z;
			 Im[WS(rs, 3)] = -(T2x + T2A);
			 Ip[WS(rs, 2)] = T2A - T2x;
		    }
		    {
			 E T1M, T1P, T2v, T2w;
			 T1M = T1K + T1L;
			 T1P = T1N + T1O;
			 Rm[WS(rs, 1)] = T1M - T1P;
			 Rp[WS(rs, 4)] = T1M + T1P;
			 T2v = T25 + T26;
			 T2w = T2t + T2q;
			 Im[WS(rs, 1)] = T2v - T2w;
			 Ip[WS(rs, 4)] = T2v + T2w;
		    }
		    {
			 E T1Q, T23, T2B, T2C;
			 T1Q = T1m - T1t;
			 T23 = T1W - T22;
			 Rm[0] = T1Q - T23;
			 Rp[WS(rs, 5)] = T1Q + T23;
			 T2B = T1I - T1B;
			 T2C = T2z - T2y;
			 Im[0] = T2B - T2C;
			 Ip[WS(rs, 5)] = T2B + T2C;
		    }
		    {
			 E T24, T27, T2n, T2u;
			 T24 = T1K - T1L;
			 T27 = T25 - T26;
			 Rm[WS(rs, 4)] = T24 - T27;
			 Rp[WS(rs, 1)] = T24 + T27;
			 T2n = T1O - T1N;
			 T2u = T2q - T2t;
			 Im[WS(rs, 4)] = T2n - T2u;
			 Ip[WS(rs, 1)] = T2n + T2u;
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 12 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 12, "hc2cf_12", twinstr, &GENUS, { 72, 22, 46, 0 } };

void X(codelet_hc2cf_12) (planner *p) {
     X(khc2c_register) (p, hc2cf_12, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4 -pipeline-latency 4 -n 12 -dit -name hc2cf_12 -include hc2cf.h */

/*
 * This function contains 118 FP additions, 60 FP multiplications,
 * (or, 88 additions, 30 multiplications, 30 fused multiply/add),
 * 47 stack variables, 2 constants, and 48 memory accesses
 */
#include "hc2cf.h"

static void hc2cf_12(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 22); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 22, MAKE_VOLATILE_STRIDE(48, rs)) {
	       E T1, T1W, T18, T22, Tc, T15, T1V, T23, TR, T1E, T1o, T1D, T12, T1l, T1F;
	       E T1G, Ti, T1S, T1d, T25, Tt, T1a, T1T, T26, TA, T1y, T1j, T1B, TL, T1g;
	       E T1z, T1A;
	       {
		    E T6, T16, Tb, T17;
		    T1 = Rp[0];
		    T1W = Rm[0];
		    {
			 E T3, T5, T2, T4;
			 T3 = Rp[WS(rs, 2)];
			 T5 = Rm[WS(rs, 2)];
			 T2 = W[6];
			 T4 = W[7];
			 T6 = FMA(T2, T3, T4 * T5);
			 T16 = FNMS(T4, T3, T2 * T5);
		    }
		    {
			 E T8, Ta, T7, T9;
			 T8 = Rp[WS(rs, 4)];
			 Ta = Rm[WS(rs, 4)];
			 T7 = W[14];
			 T9 = W[15];
			 Tb = FMA(T7, T8, T9 * Ta);
			 T17 = FNMS(T9, T8, T7 * Ta);
		    }
		    T18 = KP866025403 * (T16 - T17);
		    T22 = KP866025403 * (Tb - T6);
		    Tc = T6 + Tb;
		    T15 = FNMS(KP500000000, Tc, T1);
		    T1V = T16 + T17;
		    T23 = FNMS(KP500000000, T1V, T1W);
	       }
	       {
		    E T11, T1n, TW, T1m;
		    {
			 E TO, TQ, TN, TP;
			 TO = Ip[WS(rs, 4)];
			 TQ = Im[WS(rs, 4)];
			 TN = W[16];
			 TP = W[17];
			 TR = FMA(TN, TO, TP * TQ);
			 T1E = FNMS(TP, TO, TN * TQ);
		    }
		    {
			 E TY, T10, TX, TZ;
			 TY = Ip[WS(rs, 2)];
			 T10 = Im[WS(rs, 2)];
			 TX = W[8];
			 TZ = W[9];
			 T11 = FMA(TX, TY, TZ * T10);
			 T1n = FNMS(TZ, TY, TX * T10);
		    }
		    {
			 E TT, TV, TS, TU;
			 TT = Ip[0];
			 TV = Im[0];
			 TS = W[0];
			 TU = W[1];
			 TW = FMA(TS, TT, TU * TV);
			 T1m = FNMS(TU, TT, TS * TV);
		    }
		    T1o = KP866025403 * (T1m - T1n);
		    T1D = KP866025403 * (T11 - TW);
		    T12 = TW + T11;
		    T1l = FNMS(KP500000000, T12, TR);
		    T1F = T1m + T1n;
		    T1G = FNMS(KP500000000, T1F, T1E);
	       }
	       {
		    E Ts, T1c, Tn, T1b;
		    {
			 E Tf, Th, Te, Tg;
			 Tf = Rp[WS(rs, 3)];
			 Th = Rm[WS(rs, 3)];
			 Te = W[10];
			 Tg = W[11];
			 Ti = FMA(Te, Tf, Tg * Th);
			 T1S = FNMS(Tg, Tf, Te * Th);
		    }
		    {
			 E Tp, Tr, To, Tq;
			 Tp = Rp[WS(rs, 1)];
			 Tr = Rm[WS(rs, 1)];
			 To = W[2];
			 Tq = W[3];
			 Ts = FMA(To, Tp, Tq * Tr);
			 T1c = FNMS(Tq, Tp, To * Tr);
		    }
		    {
			 E Tk, Tm, Tj, Tl;
			 Tk = Rp[WS(rs, 5)];
			 Tm = Rm[WS(rs, 5)];
			 Tj = W[18];
			 Tl = W[19];
			 Tn = FMA(Tj, Tk, Tl * Tm);
			 T1b = FNMS(Tl, Tk, Tj * Tm);
		    }
		    T1d = KP866025403 * (T1b - T1c);
		    T25 = KP866025403 * (Ts - Tn);
		    Tt = Tn + Ts;
		    T1a = FNMS(KP500000000, Tt, Ti);
		    T1T = T1b + T1c;
		    T26 = FNMS(KP500000000, T1T, T1S);
	       }
	       {
		    E TK, T1i, TF, T1h;
		    {
			 E Tx, Tz, Tw, Ty;
			 Tx = Ip[WS(rs, 1)];
			 Tz = Im[WS(rs, 1)];
			 Tw = W[4];
			 Ty = W[5];
			 TA = FMA(Tw, Tx, Ty * Tz);
			 T1y = FNMS(Ty, Tx, Tw * Tz);
		    }
		    {
			 E TH, TJ, TG, TI;
			 TH = Ip[WS(rs, 5)];
			 TJ = Im[WS(rs, 5)];
			 TG = W[20];
			 TI = W[21];
			 TK = FMA(TG, TH, TI * TJ);
			 T1i = FNMS(TI, TH, TG * TJ);
		    }
		    {
			 E TC, TE, TB, TD;
			 TC = Ip[WS(rs, 3)];
			 TE = Im[WS(rs, 3)];
			 TB = W[12];
			 TD = W[13];
			 TF = FMA(TB, TC, TD * TE);
			 T1h = FNMS(TD, TC, TB * TE);
		    }
		    T1j = KP866025403 * (T1h - T1i);
		    T1B = KP866025403 * (TK - TF);
		    TL = TF + TK;
		    T1g = FNMS(KP500000000, TL, TA);
		    T1z = T1h + T1i;
		    T1A = FNMS(KP500000000, T1z, T1y);
	       }
	       {
		    E Tv, T1N, T1Y, T20, T14, T1Z, T1Q, T1R;
		    {
			 E Td, Tu, T1U, T1X;
			 Td = T1 + Tc;
			 Tu = Ti + Tt;
			 Tv = Td + Tu;
			 T1N = Td - Tu;
			 T1U = T1S + T1T;
			 T1X = T1V + T1W;
			 T1Y = T1U + T1X;
			 T20 = T1X - T1U;
		    }
		    {
			 E TM, T13, T1O, T1P;
			 TM = TA + TL;
			 T13 = TR + T12;
			 T14 = TM + T13;
			 T1Z = TM - T13;
			 T1O = T1y + T1z;
			 T1P = T1E + T1F;
			 T1Q = T1O - T1P;
			 T1R = T1O + T1P;
		    }
		    Rm[WS(rs, 5)] = Tv - T14;
		    Im[WS(rs, 5)] = T1R - T1Y;
		    Rp[0] = Tv + T14;
		    Ip[0] = T1R + T1Y;
		    Rp[WS(rs, 3)] = T1N - T1Q;
		    Ip[WS(rs, 3)] = T1Z + T20;
		    Rm[WS(rs, 2)] = T1N + T1Q;
		    Im[WS(rs, 2)] = T1Z - T20;
	       }
	       {
		    E T1t, T1J, T28, T2a, T1w, T21, T1M, T29;
		    {
			 E T1r, T1s, T24, T27;
			 T1r = T15 + T18;
			 T1s = T1a + T1d;
			 T1t = T1r + T1s;
			 T1J = T1r - T1s;
			 T24 = T22 + T23;
			 T27 = T25 + T26;
			 T28 = T24 - T27;
			 T2a = T27 + T24;
		    }
		    {
			 E T1u, T1v, T1K, T1L;
			 T1u = T1g + T1j;
			 T1v = T1l + T1o;
			 T1w = T1u + T1v;
			 T21 = T1v - T1u;
			 T1K = T1B + T1A;
			 T1L = T1D + T1G;
			 T1M = T1K - T1L;
			 T29 = T1K + T1L;
		    }
		    Rm[WS(rs, 1)] = T1t - T1w;
		    Im[WS(rs, 1)] = T29 - T2a;
		    Rp[WS(rs, 4)] = T1t + T1w;
		    Ip[WS(rs, 4)] = T29 + T2a;
		    Rm[WS(rs, 4)] = T1J - T1M;
		    Im[WS(rs, 4)] = T21 - T28;
		    Rp[WS(rs, 1)] = T1J + T1M;
		    Ip[WS(rs, 1)] = T21 + T28;
	       }
	       {
		    E T1f, T1x, T2e, T2g, T1q, T2f, T1I, T2b;
		    {
			 E T19, T1e, T2c, T2d;
			 T19 = T15 - T18;
			 T1e = T1a - T1d;
			 T1f = T19 + T1e;
			 T1x = T19 - T1e;
			 T2c = T26 - T25;
			 T2d = T23 - T22;
			 T2e = T2c + T2d;
			 T2g = T2d - T2c;
		    }
		    {
			 E T1k, T1p, T1C, T1H;
			 T1k = T1g - T1j;
			 T1p = T1l - T1o;
			 T1q = T1k + T1p;
			 T2f = T1p - T1k;
			 T1C = T1A - T1B;
			 T1H = T1D - T1G;
			 T1I = T1C + T1H;
			 T2b = T1H - T1C;
		    }
		    Rp[WS(rs, 2)] = T1f - T1q;
		    Ip[WS(rs, 2)] = T2b + T2e;
		    Rm[WS(rs, 3)] = T1f + T1q;
		    Im[WS(rs, 3)] = T2b - T2e;
		    Rm[0] = T1x - T1I;
		    Im[0] = T2f - T2g;
		    Rp[WS(rs, 5)] = T1x + T1I;
		    Ip[WS(rs, 5)] = T2f + T2g;
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 12 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 12, "hc2cf_12", twinstr, &GENUS, { 88, 30, 30, 0 } };

void X(codelet_hc2cf_12) (planner *p) {
     X(khc2c_register) (p, hc2cf_12, &desc, HC2C_VIA_RDFT);
}
#endif

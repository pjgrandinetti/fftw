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
/* Generated on Thu Dec 10 07:04:25 EST 2020 */

#include "codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twidsq.native -fma -compact -variables 4 -pipeline-latency 4 -reload-twiddle -dif -n 5 -name q1_5 -include q.h */

/*
 * This function contains 200 FP additions, 170 FP multiplications,
 * (or, 70 additions, 40 multiplications, 130 fused multiply/add),
 * 75 stack variables, 4 constants, and 100 memory accesses
 */
#include "q.h"

static void q1_5(R *rio, R *iio, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT m;
	  for (m = mb, W = W + (mb * 8); m < me; m = m + 1, rio = rio + ms, iio = iio + ms, W = W + 8, MAKE_VOLATILE_STRIDE(10, rs), MAKE_VOLATILE_STRIDE(0, vs)) {
	       E T1, Tb, TM, Tw, T8, Ta, Tn, Tj, TH, Ts, Tq, Tr, TV, T15, T1G;
	       E T1q, T12, T14, T1h, T1d, T1B, T1m, T1k, T1l, T1P, T1Z, T2A, T2k, T1W, T1Y;
	       E T2b, T27, T2v, T2g, T2e, T2f, T3Z, T3V, T4j, T44, T42, T43, T3D, T3N, T4o;
	       E T48, T3K, T3M, T2J, T2T, T3u, T3e, T2Q, T2S, T35, T31, T3p, T3a, T38, T39;
	       {
		    E T7, Tv, T4, Tu;
		    T1 = rio[0];
		    {
			 E T5, T6, T2, T3;
			 T5 = rio[WS(rs, 2)];
			 T6 = rio[WS(rs, 3)];
			 T7 = T5 + T6;
			 Tv = T5 - T6;
			 T2 = rio[WS(rs, 1)];
			 T3 = rio[WS(rs, 4)];
			 T4 = T2 + T3;
			 Tu = T2 - T3;
		    }
		    Tb = T4 - T7;
		    TM = FNMS(KP618033988, Tu, Tv);
		    Tw = FMA(KP618033988, Tv, Tu);
		    T8 = T4 + T7;
		    Ta = FNMS(KP250000000, T8, T1);
	       }
	       {
		    E Ti, Tp, Tf, To;
		    Tn = iio[0];
		    {
			 E Tg, Th, Td, Te;
			 Tg = iio[WS(rs, 2)];
			 Th = iio[WS(rs, 3)];
			 Ti = Tg - Th;
			 Tp = Tg + Th;
			 Td = iio[WS(rs, 1)];
			 Te = iio[WS(rs, 4)];
			 Tf = Td - Te;
			 To = Td + Te;
		    }
		    Tj = FMA(KP618033988, Ti, Tf);
		    TH = FNMS(KP618033988, Tf, Ti);
		    Ts = To - Tp;
		    Tq = To + Tp;
		    Tr = FNMS(KP250000000, Tq, Tn);
	       }
	       {
		    E T11, T1p, TY, T1o;
		    TV = rio[WS(vs, 1)];
		    {
			 E TZ, T10, TW, TX;
			 TZ = rio[WS(vs, 1) + WS(rs, 2)];
			 T10 = rio[WS(vs, 1) + WS(rs, 3)];
			 T11 = TZ + T10;
			 T1p = TZ - T10;
			 TW = rio[WS(vs, 1) + WS(rs, 1)];
			 TX = rio[WS(vs, 1) + WS(rs, 4)];
			 TY = TW + TX;
			 T1o = TW - TX;
		    }
		    T15 = TY - T11;
		    T1G = FNMS(KP618033988, T1o, T1p);
		    T1q = FMA(KP618033988, T1p, T1o);
		    T12 = TY + T11;
		    T14 = FNMS(KP250000000, T12, TV);
	       }
	       {
		    E T1c, T1j, T19, T1i;
		    T1h = iio[WS(vs, 1)];
		    {
			 E T1a, T1b, T17, T18;
			 T1a = iio[WS(vs, 1) + WS(rs, 2)];
			 T1b = iio[WS(vs, 1) + WS(rs, 3)];
			 T1c = T1a - T1b;
			 T1j = T1a + T1b;
			 T17 = iio[WS(vs, 1) + WS(rs, 1)];
			 T18 = iio[WS(vs, 1) + WS(rs, 4)];
			 T19 = T17 - T18;
			 T1i = T17 + T18;
		    }
		    T1d = FMA(KP618033988, T1c, T19);
		    T1B = FNMS(KP618033988, T19, T1c);
		    T1m = T1i - T1j;
		    T1k = T1i + T1j;
		    T1l = FNMS(KP250000000, T1k, T1h);
	       }
	       {
		    E T1V, T2j, T1S, T2i;
		    T1P = rio[WS(vs, 2)];
		    {
			 E T1T, T1U, T1Q, T1R;
			 T1T = rio[WS(vs, 2) + WS(rs, 2)];
			 T1U = rio[WS(vs, 2) + WS(rs, 3)];
			 T1V = T1T + T1U;
			 T2j = T1T - T1U;
			 T1Q = rio[WS(vs, 2) + WS(rs, 1)];
			 T1R = rio[WS(vs, 2) + WS(rs, 4)];
			 T1S = T1Q + T1R;
			 T2i = T1Q - T1R;
		    }
		    T1Z = T1S - T1V;
		    T2A = FNMS(KP618033988, T2i, T2j);
		    T2k = FMA(KP618033988, T2j, T2i);
		    T1W = T1S + T1V;
		    T1Y = FNMS(KP250000000, T1W, T1P);
	       }
	       {
		    E T26, T2d, T23, T2c;
		    T2b = iio[WS(vs, 2)];
		    {
			 E T24, T25, T21, T22;
			 T24 = iio[WS(vs, 2) + WS(rs, 2)];
			 T25 = iio[WS(vs, 2) + WS(rs, 3)];
			 T26 = T24 - T25;
			 T2d = T24 + T25;
			 T21 = iio[WS(vs, 2) + WS(rs, 1)];
			 T22 = iio[WS(vs, 2) + WS(rs, 4)];
			 T23 = T21 - T22;
			 T2c = T21 + T22;
		    }
		    T27 = FMA(KP618033988, T26, T23);
		    T2v = FNMS(KP618033988, T23, T26);
		    T2g = T2c - T2d;
		    T2e = T2c + T2d;
		    T2f = FNMS(KP250000000, T2e, T2b);
	       }
	       {
		    E T3U, T41, T3R, T40;
		    T3Z = iio[WS(vs, 4)];
		    {
			 E T3S, T3T, T3P, T3Q;
			 T3S = iio[WS(vs, 4) + WS(rs, 2)];
			 T3T = iio[WS(vs, 4) + WS(rs, 3)];
			 T3U = T3S - T3T;
			 T41 = T3S + T3T;
			 T3P = iio[WS(vs, 4) + WS(rs, 1)];
			 T3Q = iio[WS(vs, 4) + WS(rs, 4)];
			 T3R = T3P - T3Q;
			 T40 = T3P + T3Q;
		    }
		    T3V = FMA(KP618033988, T3U, T3R);
		    T4j = FNMS(KP618033988, T3R, T3U);
		    T44 = T40 - T41;
		    T42 = T40 + T41;
		    T43 = FNMS(KP250000000, T42, T3Z);
	       }
	       {
		    E T3J, T47, T3G, T46;
		    T3D = rio[WS(vs, 4)];
		    {
			 E T3H, T3I, T3E, T3F;
			 T3H = rio[WS(vs, 4) + WS(rs, 2)];
			 T3I = rio[WS(vs, 4) + WS(rs, 3)];
			 T3J = T3H + T3I;
			 T47 = T3H - T3I;
			 T3E = rio[WS(vs, 4) + WS(rs, 1)];
			 T3F = rio[WS(vs, 4) + WS(rs, 4)];
			 T3G = T3E + T3F;
			 T46 = T3E - T3F;
		    }
		    T3N = T3G - T3J;
		    T4o = FNMS(KP618033988, T46, T47);
		    T48 = FMA(KP618033988, T47, T46);
		    T3K = T3G + T3J;
		    T3M = FNMS(KP250000000, T3K, T3D);
	       }
	       {
		    E T2P, T3d, T2M, T3c;
		    T2J = rio[WS(vs, 3)];
		    {
			 E T2N, T2O, T2K, T2L;
			 T2N = rio[WS(vs, 3) + WS(rs, 2)];
			 T2O = rio[WS(vs, 3) + WS(rs, 3)];
			 T2P = T2N + T2O;
			 T3d = T2N - T2O;
			 T2K = rio[WS(vs, 3) + WS(rs, 1)];
			 T2L = rio[WS(vs, 3) + WS(rs, 4)];
			 T2M = T2K + T2L;
			 T3c = T2K - T2L;
		    }
		    T2T = T2M - T2P;
		    T3u = FNMS(KP618033988, T3c, T3d);
		    T3e = FMA(KP618033988, T3d, T3c);
		    T2Q = T2M + T2P;
		    T2S = FNMS(KP250000000, T2Q, T2J);
	       }
	       {
		    E T30, T37, T2X, T36;
		    T35 = iio[WS(vs, 3)];
		    {
			 E T2Y, T2Z, T2V, T2W;
			 T2Y = iio[WS(vs, 3) + WS(rs, 2)];
			 T2Z = iio[WS(vs, 3) + WS(rs, 3)];
			 T30 = T2Y - T2Z;
			 T37 = T2Y + T2Z;
			 T2V = iio[WS(vs, 3) + WS(rs, 1)];
			 T2W = iio[WS(vs, 3) + WS(rs, 4)];
			 T2X = T2V - T2W;
			 T36 = T2V + T2W;
		    }
		    T31 = FMA(KP618033988, T30, T2X);
		    T3p = FNMS(KP618033988, T2X, T30);
		    T3a = T36 - T37;
		    T38 = T36 + T37;
		    T39 = FNMS(KP250000000, T38, T35);
	       }
	       rio[0] = T1 + T8;
	       iio[0] = Tn + Tq;
	       rio[WS(rs, 1)] = TV + T12;
	       iio[WS(rs, 1)] = T1h + T1k;
	       rio[WS(rs, 2)] = T1P + T1W;
	       iio[WS(rs, 2)] = T2b + T2e;
	       iio[WS(rs, 4)] = T3Z + T42;
	       rio[WS(rs, 4)] = T3D + T3K;
	       rio[WS(rs, 3)] = T2J + T2Q;
	       iio[WS(rs, 3)] = T35 + T38;
	       {
		    E Tk, TA, Tx, TD, Tc, Tt;
		    Tc = FMA(KP559016994, Tb, Ta);
		    Tk = FMA(KP951056516, Tj, Tc);
		    TA = FNMS(KP951056516, Tj, Tc);
		    Tt = FMA(KP559016994, Ts, Tr);
		    Tx = FNMS(KP951056516, Tw, Tt);
		    TD = FMA(KP951056516, Tw, Tt);
		    {
			 E Tl, Ty, T9, Tm;
			 T9 = W[0];
			 Tl = T9 * Tk;
			 Ty = T9 * Tx;
			 Tm = W[1];
			 rio[WS(vs, 1)] = FMA(Tm, Tx, Tl);
			 iio[WS(vs, 1)] = FNMS(Tm, Tk, Ty);
		    }
		    {
			 E TB, TE, Tz, TC;
			 Tz = W[6];
			 TB = Tz * TA;
			 TE = Tz * TD;
			 TC = W[7];
			 rio[WS(vs, 4)] = FMA(TC, TD, TB);
			 iio[WS(vs, 4)] = FNMS(TC, TA, TE);
		    }
	       }
	       {
		    E TI, TQ, TN, TT, TG, TL;
		    TG = FNMS(KP559016994, Tb, Ta);
		    TI = FNMS(KP951056516, TH, TG);
		    TQ = FMA(KP951056516, TH, TG);
		    TL = FNMS(KP559016994, Ts, Tr);
		    TN = FMA(KP951056516, TM, TL);
		    TT = FNMS(KP951056516, TM, TL);
		    {
			 E TJ, TO, TF, TK;
			 TF = W[2];
			 TJ = TF * TI;
			 TO = TF * TN;
			 TK = W[3];
			 rio[WS(vs, 2)] = FMA(TK, TN, TJ);
			 iio[WS(vs, 2)] = FNMS(TK, TI, TO);
		    }
		    {
			 E TR, TU, TP, TS;
			 TP = W[4];
			 TR = TP * TQ;
			 TU = TP * TT;
			 TS = W[5];
			 rio[WS(vs, 3)] = FMA(TS, TT, TR);
			 iio[WS(vs, 3)] = FNMS(TS, TQ, TU);
		    }
	       }
	       {
		    E T2w, T2E, T2B, T2H, T2u, T2z;
		    T2u = FNMS(KP559016994, T1Z, T1Y);
		    T2w = FNMS(KP951056516, T2v, T2u);
		    T2E = FMA(KP951056516, T2v, T2u);
		    T2z = FNMS(KP559016994, T2g, T2f);
		    T2B = FMA(KP951056516, T2A, T2z);
		    T2H = FNMS(KP951056516, T2A, T2z);
		    {
			 E T2x, T2C, T2t, T2y;
			 T2t = W[2];
			 T2x = T2t * T2w;
			 T2C = T2t * T2B;
			 T2y = W[3];
			 rio[WS(vs, 2) + WS(rs, 2)] = FMA(T2y, T2B, T2x);
			 iio[WS(vs, 2) + WS(rs, 2)] = FNMS(T2y, T2w, T2C);
		    }
		    {
			 E T2F, T2I, T2D, T2G;
			 T2D = W[4];
			 T2F = T2D * T2E;
			 T2I = T2D * T2H;
			 T2G = W[5];
			 rio[WS(vs, 3) + WS(rs, 2)] = FMA(T2G, T2H, T2F);
			 iio[WS(vs, 3) + WS(rs, 2)] = FNMS(T2G, T2E, T2I);
		    }
	       }
	       {
		    E T4k, T4s, T4p, T4v, T4i, T4n;
		    T4i = FNMS(KP559016994, T3N, T3M);
		    T4k = FNMS(KP951056516, T4j, T4i);
		    T4s = FMA(KP951056516, T4j, T4i);
		    T4n = FNMS(KP559016994, T44, T43);
		    T4p = FMA(KP951056516, T4o, T4n);
		    T4v = FNMS(KP951056516, T4o, T4n);
		    {
			 E T4l, T4q, T4h, T4m;
			 T4h = W[2];
			 T4l = T4h * T4k;
			 T4q = T4h * T4p;
			 T4m = W[3];
			 rio[WS(vs, 2) + WS(rs, 4)] = FMA(T4m, T4p, T4l);
			 iio[WS(vs, 2) + WS(rs, 4)] = FNMS(T4m, T4k, T4q);
		    }
		    {
			 E T4t, T4w, T4r, T4u;
			 T4r = W[4];
			 T4t = T4r * T4s;
			 T4w = T4r * T4v;
			 T4u = W[5];
			 rio[WS(vs, 3) + WS(rs, 4)] = FMA(T4u, T4v, T4t);
			 iio[WS(vs, 3) + WS(rs, 4)] = FNMS(T4u, T4s, T4w);
		    }
	       }
	       {
		    E T28, T2o, T2l, T2r, T20, T2h;
		    T20 = FMA(KP559016994, T1Z, T1Y);
		    T28 = FMA(KP951056516, T27, T20);
		    T2o = FNMS(KP951056516, T27, T20);
		    T2h = FMA(KP559016994, T2g, T2f);
		    T2l = FNMS(KP951056516, T2k, T2h);
		    T2r = FMA(KP951056516, T2k, T2h);
		    {
			 E T29, T2m, T1X, T2a;
			 T1X = W[0];
			 T29 = T1X * T28;
			 T2m = T1X * T2l;
			 T2a = W[1];
			 rio[WS(vs, 1) + WS(rs, 2)] = FMA(T2a, T2l, T29);
			 iio[WS(vs, 1) + WS(rs, 2)] = FNMS(T2a, T28, T2m);
		    }
		    {
			 E T2p, T2s, T2n, T2q;
			 T2n = W[6];
			 T2p = T2n * T2o;
			 T2s = T2n * T2r;
			 T2q = W[7];
			 rio[WS(vs, 4) + WS(rs, 2)] = FMA(T2q, T2r, T2p);
			 iio[WS(vs, 4) + WS(rs, 2)] = FNMS(T2q, T2o, T2s);
		    }
	       }
	       {
		    E T32, T3i, T3f, T3l, T2U, T3b;
		    T2U = FMA(KP559016994, T2T, T2S);
		    T32 = FMA(KP951056516, T31, T2U);
		    T3i = FNMS(KP951056516, T31, T2U);
		    T3b = FMA(KP559016994, T3a, T39);
		    T3f = FNMS(KP951056516, T3e, T3b);
		    T3l = FMA(KP951056516, T3e, T3b);
		    {
			 E T33, T3g, T2R, T34;
			 T2R = W[0];
			 T33 = T2R * T32;
			 T3g = T2R * T3f;
			 T34 = W[1];
			 rio[WS(vs, 1) + WS(rs, 3)] = FMA(T34, T3f, T33);
			 iio[WS(vs, 1) + WS(rs, 3)] = FNMS(T34, T32, T3g);
		    }
		    {
			 E T3j, T3m, T3h, T3k;
			 T3h = W[6];
			 T3j = T3h * T3i;
			 T3m = T3h * T3l;
			 T3k = W[7];
			 rio[WS(vs, 4) + WS(rs, 3)] = FMA(T3k, T3l, T3j);
			 iio[WS(vs, 4) + WS(rs, 3)] = FNMS(T3k, T3i, T3m);
		    }
	       }
	       {
		    E T3q, T3y, T3v, T3B, T3o, T3t;
		    T3o = FNMS(KP559016994, T2T, T2S);
		    T3q = FNMS(KP951056516, T3p, T3o);
		    T3y = FMA(KP951056516, T3p, T3o);
		    T3t = FNMS(KP559016994, T3a, T39);
		    T3v = FMA(KP951056516, T3u, T3t);
		    T3B = FNMS(KP951056516, T3u, T3t);
		    {
			 E T3r, T3w, T3n, T3s;
			 T3n = W[2];
			 T3r = T3n * T3q;
			 T3w = T3n * T3v;
			 T3s = W[3];
			 rio[WS(vs, 2) + WS(rs, 3)] = FMA(T3s, T3v, T3r);
			 iio[WS(vs, 2) + WS(rs, 3)] = FNMS(T3s, T3q, T3w);
		    }
		    {
			 E T3z, T3C, T3x, T3A;
			 T3x = W[4];
			 T3z = T3x * T3y;
			 T3C = T3x * T3B;
			 T3A = W[5];
			 rio[WS(vs, 3) + WS(rs, 3)] = FMA(T3A, T3B, T3z);
			 iio[WS(vs, 3) + WS(rs, 3)] = FNMS(T3A, T3y, T3C);
		    }
	       }
	       {
		    E T3W, T4c, T49, T4f, T3O, T45;
		    T3O = FMA(KP559016994, T3N, T3M);
		    T3W = FMA(KP951056516, T3V, T3O);
		    T4c = FNMS(KP951056516, T3V, T3O);
		    T45 = FMA(KP559016994, T44, T43);
		    T49 = FNMS(KP951056516, T48, T45);
		    T4f = FMA(KP951056516, T48, T45);
		    {
			 E T3X, T4a, T3L, T3Y;
			 T3L = W[0];
			 T3X = T3L * T3W;
			 T4a = T3L * T49;
			 T3Y = W[1];
			 rio[WS(vs, 1) + WS(rs, 4)] = FMA(T3Y, T49, T3X);
			 iio[WS(vs, 1) + WS(rs, 4)] = FNMS(T3Y, T3W, T4a);
		    }
		    {
			 E T4d, T4g, T4b, T4e;
			 T4b = W[6];
			 T4d = T4b * T4c;
			 T4g = T4b * T4f;
			 T4e = W[7];
			 rio[WS(vs, 4) + WS(rs, 4)] = FMA(T4e, T4f, T4d);
			 iio[WS(vs, 4) + WS(rs, 4)] = FNMS(T4e, T4c, T4g);
		    }
	       }
	       {
		    E T1C, T1K, T1H, T1N, T1A, T1F;
		    T1A = FNMS(KP559016994, T15, T14);
		    T1C = FNMS(KP951056516, T1B, T1A);
		    T1K = FMA(KP951056516, T1B, T1A);
		    T1F = FNMS(KP559016994, T1m, T1l);
		    T1H = FMA(KP951056516, T1G, T1F);
		    T1N = FNMS(KP951056516, T1G, T1F);
		    {
			 E T1D, T1I, T1z, T1E;
			 T1z = W[2];
			 T1D = T1z * T1C;
			 T1I = T1z * T1H;
			 T1E = W[3];
			 rio[WS(vs, 2) + WS(rs, 1)] = FMA(T1E, T1H, T1D);
			 iio[WS(vs, 2) + WS(rs, 1)] = FNMS(T1E, T1C, T1I);
		    }
		    {
			 E T1L, T1O, T1J, T1M;
			 T1J = W[4];
			 T1L = T1J * T1K;
			 T1O = T1J * T1N;
			 T1M = W[5];
			 rio[WS(vs, 3) + WS(rs, 1)] = FMA(T1M, T1N, T1L);
			 iio[WS(vs, 3) + WS(rs, 1)] = FNMS(T1M, T1K, T1O);
		    }
	       }
	       {
		    E T1e, T1u, T1r, T1x, T16, T1n;
		    T16 = FMA(KP559016994, T15, T14);
		    T1e = FMA(KP951056516, T1d, T16);
		    T1u = FNMS(KP951056516, T1d, T16);
		    T1n = FMA(KP559016994, T1m, T1l);
		    T1r = FNMS(KP951056516, T1q, T1n);
		    T1x = FMA(KP951056516, T1q, T1n);
		    {
			 E T1f, T1s, T13, T1g;
			 T13 = W[0];
			 T1f = T13 * T1e;
			 T1s = T13 * T1r;
			 T1g = W[1];
			 rio[WS(vs, 1) + WS(rs, 1)] = FMA(T1g, T1r, T1f);
			 iio[WS(vs, 1) + WS(rs, 1)] = FNMS(T1g, T1e, T1s);
		    }
		    {
			 E T1v, T1y, T1t, T1w;
			 T1t = W[6];
			 T1v = T1t * T1u;
			 T1y = T1t * T1x;
			 T1w = W[7];
			 rio[WS(vs, 4) + WS(rs, 1)] = FMA(T1w, T1x, T1v);
			 iio[WS(vs, 4) + WS(rs, 1)] = FNMS(T1w, T1u, T1y);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 0, 5 },
     { TW_NEXT, 1, 0 }
};

static const ct_desc desc = { 5, "q1_5", twinstr, &GENUS, { 70, 40, 130, 0 }, 0, 0, 0 };

void X(codelet_q1_5) (planner *p) {
     X(kdft_difsq_register) (p, q1_5, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twidsq.native -compact -variables 4 -pipeline-latency 4 -reload-twiddle -dif -n 5 -name q1_5 -include q.h */

/*
 * This function contains 200 FP additions, 140 FP multiplications,
 * (or, 130 additions, 70 multiplications, 70 fused multiply/add),
 * 75 stack variables, 4 constants, and 100 memory accesses
 */
#include "q.h"

static void q1_5(R *rio, R *iio, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT m;
	  for (m = mb, W = W + (mb * 8); m < me; m = m + 1, rio = rio + ms, iio = iio + ms, W = W + 8, MAKE_VOLATILE_STRIDE(10, rs), MAKE_VOLATILE_STRIDE(0, vs)) {
	       E T1, Ta, TG, Tv, T8, Tb, Tp, Tj, TD, To, Tq, Tr, TN, TW, T1s;
	       E T1h, TU, TX, T1b, T15, T1p, T1a, T1c, T1d, T1z, T1I, T2e, T23, T1G, T1J;
	       E T1X, T1R, T2b, T1W, T1Y, T1Z, T3v, T3p, T3J, T3u, T3w, T3x, T37, T3g, T3M;
	       E T3B, T3e, T3h, T2l, T2u, T30, T2P, T2s, T2v, T2J, T2D, T2X, T2I, T2K, T2L;
	       {
		    E T7, Tu, T4, Tt;
		    T1 = rio[0];
		    {
			 E T5, T6, T2, T3;
			 T5 = rio[WS(rs, 2)];
			 T6 = rio[WS(rs, 3)];
			 T7 = T5 + T6;
			 Tu = T5 - T6;
			 T2 = rio[WS(rs, 1)];
			 T3 = rio[WS(rs, 4)];
			 T4 = T2 + T3;
			 Tt = T2 - T3;
		    }
		    Ta = KP559016994 * (T4 - T7);
		    TG = FNMS(KP587785252, Tt, KP951056516 * Tu);
		    Tv = FMA(KP951056516, Tt, KP587785252 * Tu);
		    T8 = T4 + T7;
		    Tb = FNMS(KP250000000, T8, T1);
	       }
	       {
		    E Ti, Tn, Tf, Tm;
		    Tp = iio[0];
		    {
			 E Tg, Th, Td, Te;
			 Tg = iio[WS(rs, 2)];
			 Th = iio[WS(rs, 3)];
			 Ti = Tg - Th;
			 Tn = Tg + Th;
			 Td = iio[WS(rs, 1)];
			 Te = iio[WS(rs, 4)];
			 Tf = Td - Te;
			 Tm = Td + Te;
		    }
		    Tj = FMA(KP951056516, Tf, KP587785252 * Ti);
		    TD = FNMS(KP587785252, Tf, KP951056516 * Ti);
		    To = KP559016994 * (Tm - Tn);
		    Tq = Tm + Tn;
		    Tr = FNMS(KP250000000, Tq, Tp);
	       }
	       {
		    E TT, T1g, TQ, T1f;
		    TN = rio[WS(vs, 1)];
		    {
			 E TR, TS, TO, TP;
			 TR = rio[WS(vs, 1) + WS(rs, 2)];
			 TS = rio[WS(vs, 1) + WS(rs, 3)];
			 TT = TR + TS;
			 T1g = TR - TS;
			 TO = rio[WS(vs, 1) + WS(rs, 1)];
			 TP = rio[WS(vs, 1) + WS(rs, 4)];
			 TQ = TO + TP;
			 T1f = TO - TP;
		    }
		    TW = KP559016994 * (TQ - TT);
		    T1s = FNMS(KP587785252, T1f, KP951056516 * T1g);
		    T1h = FMA(KP951056516, T1f, KP587785252 * T1g);
		    TU = TQ + TT;
		    TX = FNMS(KP250000000, TU, TN);
	       }
	       {
		    E T14, T19, T11, T18;
		    T1b = iio[WS(vs, 1)];
		    {
			 E T12, T13, TZ, T10;
			 T12 = iio[WS(vs, 1) + WS(rs, 2)];
			 T13 = iio[WS(vs, 1) + WS(rs, 3)];
			 T14 = T12 - T13;
			 T19 = T12 + T13;
			 TZ = iio[WS(vs, 1) + WS(rs, 1)];
			 T10 = iio[WS(vs, 1) + WS(rs, 4)];
			 T11 = TZ - T10;
			 T18 = TZ + T10;
		    }
		    T15 = FMA(KP951056516, T11, KP587785252 * T14);
		    T1p = FNMS(KP587785252, T11, KP951056516 * T14);
		    T1a = KP559016994 * (T18 - T19);
		    T1c = T18 + T19;
		    T1d = FNMS(KP250000000, T1c, T1b);
	       }
	       {
		    E T1F, T22, T1C, T21;
		    T1z = rio[WS(vs, 2)];
		    {
			 E T1D, T1E, T1A, T1B;
			 T1D = rio[WS(vs, 2) + WS(rs, 2)];
			 T1E = rio[WS(vs, 2) + WS(rs, 3)];
			 T1F = T1D + T1E;
			 T22 = T1D - T1E;
			 T1A = rio[WS(vs, 2) + WS(rs, 1)];
			 T1B = rio[WS(vs, 2) + WS(rs, 4)];
			 T1C = T1A + T1B;
			 T21 = T1A - T1B;
		    }
		    T1I = KP559016994 * (T1C - T1F);
		    T2e = FNMS(KP587785252, T21, KP951056516 * T22);
		    T23 = FMA(KP951056516, T21, KP587785252 * T22);
		    T1G = T1C + T1F;
		    T1J = FNMS(KP250000000, T1G, T1z);
	       }
	       {
		    E T1Q, T1V, T1N, T1U;
		    T1X = iio[WS(vs, 2)];
		    {
			 E T1O, T1P, T1L, T1M;
			 T1O = iio[WS(vs, 2) + WS(rs, 2)];
			 T1P = iio[WS(vs, 2) + WS(rs, 3)];
			 T1Q = T1O - T1P;
			 T1V = T1O + T1P;
			 T1L = iio[WS(vs, 2) + WS(rs, 1)];
			 T1M = iio[WS(vs, 2) + WS(rs, 4)];
			 T1N = T1L - T1M;
			 T1U = T1L + T1M;
		    }
		    T1R = FMA(KP951056516, T1N, KP587785252 * T1Q);
		    T2b = FNMS(KP587785252, T1N, KP951056516 * T1Q);
		    T1W = KP559016994 * (T1U - T1V);
		    T1Y = T1U + T1V;
		    T1Z = FNMS(KP250000000, T1Y, T1X);
	       }
	       {
		    E T3o, T3t, T3l, T3s;
		    T3v = iio[WS(vs, 4)];
		    {
			 E T3m, T3n, T3j, T3k;
			 T3m = iio[WS(vs, 4) + WS(rs, 2)];
			 T3n = iio[WS(vs, 4) + WS(rs, 3)];
			 T3o = T3m - T3n;
			 T3t = T3m + T3n;
			 T3j = iio[WS(vs, 4) + WS(rs, 1)];
			 T3k = iio[WS(vs, 4) + WS(rs, 4)];
			 T3l = T3j - T3k;
			 T3s = T3j + T3k;
		    }
		    T3p = FMA(KP951056516, T3l, KP587785252 * T3o);
		    T3J = FNMS(KP587785252, T3l, KP951056516 * T3o);
		    T3u = KP559016994 * (T3s - T3t);
		    T3w = T3s + T3t;
		    T3x = FNMS(KP250000000, T3w, T3v);
	       }
	       {
		    E T3d, T3A, T3a, T3z;
		    T37 = rio[WS(vs, 4)];
		    {
			 E T3b, T3c, T38, T39;
			 T3b = rio[WS(vs, 4) + WS(rs, 2)];
			 T3c = rio[WS(vs, 4) + WS(rs, 3)];
			 T3d = T3b + T3c;
			 T3A = T3b - T3c;
			 T38 = rio[WS(vs, 4) + WS(rs, 1)];
			 T39 = rio[WS(vs, 4) + WS(rs, 4)];
			 T3a = T38 + T39;
			 T3z = T38 - T39;
		    }
		    T3g = KP559016994 * (T3a - T3d);
		    T3M = FNMS(KP587785252, T3z, KP951056516 * T3A);
		    T3B = FMA(KP951056516, T3z, KP587785252 * T3A);
		    T3e = T3a + T3d;
		    T3h = FNMS(KP250000000, T3e, T37);
	       }
	       {
		    E T2r, T2O, T2o, T2N;
		    T2l = rio[WS(vs, 3)];
		    {
			 E T2p, T2q, T2m, T2n;
			 T2p = rio[WS(vs, 3) + WS(rs, 2)];
			 T2q = rio[WS(vs, 3) + WS(rs, 3)];
			 T2r = T2p + T2q;
			 T2O = T2p - T2q;
			 T2m = rio[WS(vs, 3) + WS(rs, 1)];
			 T2n = rio[WS(vs, 3) + WS(rs, 4)];
			 T2o = T2m + T2n;
			 T2N = T2m - T2n;
		    }
		    T2u = KP559016994 * (T2o - T2r);
		    T30 = FNMS(KP587785252, T2N, KP951056516 * T2O);
		    T2P = FMA(KP951056516, T2N, KP587785252 * T2O);
		    T2s = T2o + T2r;
		    T2v = FNMS(KP250000000, T2s, T2l);
	       }
	       {
		    E T2C, T2H, T2z, T2G;
		    T2J = iio[WS(vs, 3)];
		    {
			 E T2A, T2B, T2x, T2y;
			 T2A = iio[WS(vs, 3) + WS(rs, 2)];
			 T2B = iio[WS(vs, 3) + WS(rs, 3)];
			 T2C = T2A - T2B;
			 T2H = T2A + T2B;
			 T2x = iio[WS(vs, 3) + WS(rs, 1)];
			 T2y = iio[WS(vs, 3) + WS(rs, 4)];
			 T2z = T2x - T2y;
			 T2G = T2x + T2y;
		    }
		    T2D = FMA(KP951056516, T2z, KP587785252 * T2C);
		    T2X = FNMS(KP587785252, T2z, KP951056516 * T2C);
		    T2I = KP559016994 * (T2G - T2H);
		    T2K = T2G + T2H;
		    T2L = FNMS(KP250000000, T2K, T2J);
	       }
	       rio[0] = T1 + T8;
	       iio[0] = Tp + Tq;
	       rio[WS(rs, 1)] = TN + TU;
	       iio[WS(rs, 1)] = T1b + T1c;
	       rio[WS(rs, 2)] = T1z + T1G;
	       iio[WS(rs, 2)] = T1X + T1Y;
	       iio[WS(rs, 4)] = T3v + T3w;
	       rio[WS(rs, 4)] = T37 + T3e;
	       rio[WS(rs, 3)] = T2l + T2s;
	       iio[WS(rs, 3)] = T2J + T2K;
	       {
		    E Tk, Ty, Tw, TA, Tc, Ts;
		    Tc = Ta + Tb;
		    Tk = Tc + Tj;
		    Ty = Tc - Tj;
		    Ts = To + Tr;
		    Tw = Ts - Tv;
		    TA = Tv + Ts;
		    {
			 E T9, Tl, Tx, Tz;
			 T9 = W[0];
			 Tl = W[1];
			 rio[WS(vs, 1)] = FMA(T9, Tk, Tl * Tw);
			 iio[WS(vs, 1)] = FNMS(Tl, Tk, T9 * Tw);
			 Tx = W[6];
			 Tz = W[7];
			 rio[WS(vs, 4)] = FMA(Tx, Ty, Tz * TA);
			 iio[WS(vs, 4)] = FNMS(Tz, Ty, Tx * TA);
		    }
	       }
	       {
		    E TE, TK, TI, TM, TC, TH;
		    TC = Tb - Ta;
		    TE = TC - TD;
		    TK = TC + TD;
		    TH = Tr - To;
		    TI = TG + TH;
		    TM = TH - TG;
		    {
			 E TB, TF, TJ, TL;
			 TB = W[2];
			 TF = W[3];
			 rio[WS(vs, 2)] = FMA(TB, TE, TF * TI);
			 iio[WS(vs, 2)] = FNMS(TF, TE, TB * TI);
			 TJ = W[4];
			 TL = W[5];
			 rio[WS(vs, 3)] = FMA(TJ, TK, TL * TM);
			 iio[WS(vs, 3)] = FNMS(TL, TK, TJ * TM);
		    }
	       }
	       {
		    E T2c, T2i, T2g, T2k, T2a, T2f;
		    T2a = T1J - T1I;
		    T2c = T2a - T2b;
		    T2i = T2a + T2b;
		    T2f = T1Z - T1W;
		    T2g = T2e + T2f;
		    T2k = T2f - T2e;
		    {
			 E T29, T2d, T2h, T2j;
			 T29 = W[2];
			 T2d = W[3];
			 rio[WS(vs, 2) + WS(rs, 2)] = FMA(T29, T2c, T2d * T2g);
			 iio[WS(vs, 2) + WS(rs, 2)] = FNMS(T2d, T2c, T29 * T2g);
			 T2h = W[4];
			 T2j = W[5];
			 rio[WS(vs, 3) + WS(rs, 2)] = FMA(T2h, T2i, T2j * T2k);
			 iio[WS(vs, 3) + WS(rs, 2)] = FNMS(T2j, T2i, T2h * T2k);
		    }
	       }
	       {
		    E T3K, T3Q, T3O, T3S, T3I, T3N;
		    T3I = T3h - T3g;
		    T3K = T3I - T3J;
		    T3Q = T3I + T3J;
		    T3N = T3x - T3u;
		    T3O = T3M + T3N;
		    T3S = T3N - T3M;
		    {
			 E T3H, T3L, T3P, T3R;
			 T3H = W[2];
			 T3L = W[3];
			 rio[WS(vs, 2) + WS(rs, 4)] = FMA(T3H, T3K, T3L * T3O);
			 iio[WS(vs, 2) + WS(rs, 4)] = FNMS(T3L, T3K, T3H * T3O);
			 T3P = W[4];
			 T3R = W[5];
			 rio[WS(vs, 3) + WS(rs, 4)] = FMA(T3P, T3Q, T3R * T3S);
			 iio[WS(vs, 3) + WS(rs, 4)] = FNMS(T3R, T3Q, T3P * T3S);
		    }
	       }
	       {
		    E T1S, T26, T24, T28, T1K, T20;
		    T1K = T1I + T1J;
		    T1S = T1K + T1R;
		    T26 = T1K - T1R;
		    T20 = T1W + T1Z;
		    T24 = T20 - T23;
		    T28 = T23 + T20;
		    {
			 E T1H, T1T, T25, T27;
			 T1H = W[0];
			 T1T = W[1];
			 rio[WS(vs, 1) + WS(rs, 2)] = FMA(T1H, T1S, T1T * T24);
			 iio[WS(vs, 1) + WS(rs, 2)] = FNMS(T1T, T1S, T1H * T24);
			 T25 = W[6];
			 T27 = W[7];
			 rio[WS(vs, 4) + WS(rs, 2)] = FMA(T25, T26, T27 * T28);
			 iio[WS(vs, 4) + WS(rs, 2)] = FNMS(T27, T26, T25 * T28);
		    }
	       }
	       {
		    E T2E, T2S, T2Q, T2U, T2w, T2M;
		    T2w = T2u + T2v;
		    T2E = T2w + T2D;
		    T2S = T2w - T2D;
		    T2M = T2I + T2L;
		    T2Q = T2M - T2P;
		    T2U = T2P + T2M;
		    {
			 E T2t, T2F, T2R, T2T;
			 T2t = W[0];
			 T2F = W[1];
			 rio[WS(vs, 1) + WS(rs, 3)] = FMA(T2t, T2E, T2F * T2Q);
			 iio[WS(vs, 1) + WS(rs, 3)] = FNMS(T2F, T2E, T2t * T2Q);
			 T2R = W[6];
			 T2T = W[7];
			 rio[WS(vs, 4) + WS(rs, 3)] = FMA(T2R, T2S, T2T * T2U);
			 iio[WS(vs, 4) + WS(rs, 3)] = FNMS(T2T, T2S, T2R * T2U);
		    }
	       }
	       {
		    E T2Y, T34, T32, T36, T2W, T31;
		    T2W = T2v - T2u;
		    T2Y = T2W - T2X;
		    T34 = T2W + T2X;
		    T31 = T2L - T2I;
		    T32 = T30 + T31;
		    T36 = T31 - T30;
		    {
			 E T2V, T2Z, T33, T35;
			 T2V = W[2];
			 T2Z = W[3];
			 rio[WS(vs, 2) + WS(rs, 3)] = FMA(T2V, T2Y, T2Z * T32);
			 iio[WS(vs, 2) + WS(rs, 3)] = FNMS(T2Z, T2Y, T2V * T32);
			 T33 = W[4];
			 T35 = W[5];
			 rio[WS(vs, 3) + WS(rs, 3)] = FMA(T33, T34, T35 * T36);
			 iio[WS(vs, 3) + WS(rs, 3)] = FNMS(T35, T34, T33 * T36);
		    }
	       }
	       {
		    E T3q, T3E, T3C, T3G, T3i, T3y;
		    T3i = T3g + T3h;
		    T3q = T3i + T3p;
		    T3E = T3i - T3p;
		    T3y = T3u + T3x;
		    T3C = T3y - T3B;
		    T3G = T3B + T3y;
		    {
			 E T3f, T3r, T3D, T3F;
			 T3f = W[0];
			 T3r = W[1];
			 rio[WS(vs, 1) + WS(rs, 4)] = FMA(T3f, T3q, T3r * T3C);
			 iio[WS(vs, 1) + WS(rs, 4)] = FNMS(T3r, T3q, T3f * T3C);
			 T3D = W[6];
			 T3F = W[7];
			 rio[WS(vs, 4) + WS(rs, 4)] = FMA(T3D, T3E, T3F * T3G);
			 iio[WS(vs, 4) + WS(rs, 4)] = FNMS(T3F, T3E, T3D * T3G);
		    }
	       }
	       {
		    E T1q, T1w, T1u, T1y, T1o, T1t;
		    T1o = TX - TW;
		    T1q = T1o - T1p;
		    T1w = T1o + T1p;
		    T1t = T1d - T1a;
		    T1u = T1s + T1t;
		    T1y = T1t - T1s;
		    {
			 E T1n, T1r, T1v, T1x;
			 T1n = W[2];
			 T1r = W[3];
			 rio[WS(vs, 2) + WS(rs, 1)] = FMA(T1n, T1q, T1r * T1u);
			 iio[WS(vs, 2) + WS(rs, 1)] = FNMS(T1r, T1q, T1n * T1u);
			 T1v = W[4];
			 T1x = W[5];
			 rio[WS(vs, 3) + WS(rs, 1)] = FMA(T1v, T1w, T1x * T1y);
			 iio[WS(vs, 3) + WS(rs, 1)] = FNMS(T1x, T1w, T1v * T1y);
		    }
	       }
	       {
		    E T16, T1k, T1i, T1m, TY, T1e;
		    TY = TW + TX;
		    T16 = TY + T15;
		    T1k = TY - T15;
		    T1e = T1a + T1d;
		    T1i = T1e - T1h;
		    T1m = T1h + T1e;
		    {
			 E TV, T17, T1j, T1l;
			 TV = W[0];
			 T17 = W[1];
			 rio[WS(vs, 1) + WS(rs, 1)] = FMA(TV, T16, T17 * T1i);
			 iio[WS(vs, 1) + WS(rs, 1)] = FNMS(T17, T16, TV * T1i);
			 T1j = W[6];
			 T1l = W[7];
			 rio[WS(vs, 4) + WS(rs, 1)] = FMA(T1j, T1k, T1l * T1m);
			 iio[WS(vs, 4) + WS(rs, 1)] = FNMS(T1l, T1k, T1j * T1m);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 0, 5 },
     { TW_NEXT, 1, 0 }
};

static const ct_desc desc = { 5, "q1_5", twinstr, &GENUS, { 130, 70, 70, 0 }, 0, 0, 0 };

void X(codelet_q1_5) (planner *p) {
     X(kdft_difsq_register) (p, q1_5, &desc);
}
#endif

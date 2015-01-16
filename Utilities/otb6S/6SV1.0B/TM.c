/* TM.f -- translated by f2c (version 19970805).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#ifdef __cplusplus
extern "C" {
#endif
/* OTB patches: replace "f2c.h" by "otb_6S.h" */
/*#include "f2c.h"*/
#include "otb_6S.h"

/* Common Block Declarations */

Extern struct {
    doublereal s[1501], wlinf, wlsup;
} sixs_ffu__;

#define sixs_ffu__1 sixs_ffu__

/*<       subroutine   tm(iwa) >*/
/* Subroutine */ int tm_(integer *iwa)
{
    /* Initialized data */

    static doublereal sr[9006]	/* was [6][1501] */ = { 0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,.003,0.,0.,0.,0.,0.,.0085,0.,0.,0.,0.,0.,
	    .014,0.,0.,0.,0.,0.,.0255,0.,0.,0.,0.,0.,.037,0.,0.,0.,0.,0.,.05,
	    0.,0.,0.,0.,0.,.063,0.,0.,0.,0.,0.,.201,0.,0.,0.,0.,0.,.339,0.,0.,
	    0.,0.,0.,.503,0.,0.,0.,0.,0.,.667,0.,0.,0.,0.,0.,.6935,0.,0.,0.,
	    0.,0.,.72,0.,0.,0.,0.,0.,.7525,0.,0.,0.,0.,0.,.785,0.,0.,0.,0.,0.,
	    .803,0.,0.,0.,0.,0.,.821,0.,0.,0.,0.,0.,.837,0.,0.,0.,0.,0.,.853,
	    0.,0.,0.,0.,0.,.878,0.,0.,0.,0.,0.,.903,0.,0.,0.,0.,0.,.9135,0.,
	    0.,0.,0.,0.,.924,0.,0.,0.,0.,0.,.9355,0.,0.,0.,0.,0.,.947,0.,0.,
	    0.,0.,0.,.9625,0.,0.,0.,0.,0.,.978,0.,0.,0.,0.,0.,.9835,0.,0.,0.,
	    0.,0.,.989,.001,0.,0.,0.,0.,.986,.0055,0.,0.,0.,0.,.983,.01,0.,0.,
	    0.,0.,.906,.0165,0.,0.,0.,0.,.829,.023,0.,0.,0.,0.,.7815,.0305,0.,
	    0.,0.,0.,.734,.038,0.,0.,0.,0.,.5265,.101,0.,0.,0.,0.,.319,.164,
	    0.,0.,0.,0.,.1995,.271,0.,0.,0.,0.,.08,.378,0.,0.,0.,0.,.063,.475,
	    0.,0.,0.,0.,.046,.572,0.,0.,0.,0.,.038,.615,0.,0.,0.,0.,.03,.658,
	    0.,0.,0.,0.,.023,.6945,0.,0.,0.,0.,.016,.731,0.,0.,0.,0.,.012,
	    .7575,0.,0.,0.,0.,.008,.784,0.,0.,0.,0.,.0065,.8105,0.,0.,0.,0.,
	    .005,.837,0.,0.,0.,0.,.0045,.851,0.,0.,0.,0.,.004,.865,0.,0.,0.,
	    0.,.0035,.877,0.,0.,0.,0.,.003,.889,0.,0.,0.,0.,0.,.8965,0.,0.,0.,
	    0.,0.,.904,0.,0.,0.,0.,0.,.9055,0.,0.,0.,0.,0.,.907,0.,0.,0.,0.,
	    0.,.907,0.,0.,0.,0.,0.,.907,0.,0.,0.,0.,0.,.9095,0.,0.,0.,0.,0.,
	    .912,.002,0.,0.,0.,0.,.931,.002,0.,0.,0.,0.,.95,.002,0.,0.,0.,0.,
	    .9685,.002,0.,0.,0.,0.,.987,.002,0.,0.,0.,0.,.9951,.003,0.,0.,0.,
	    0.,.998,.004,0.,0.,0.,0.,.9705,.006,0.,0.,0.,0.,.943,.008,0.,0.,
	    0.,0.,.8655,.014,0.,0.,0.,0.,.788,.02,0.,0.,0.,0.,.625,.029,0.,0.,
	    0.,0.,.462,.038,0.,0.,0.,0.,.333,.073,0.,0.,0.,0.,.204,.108,0.,0.,
	    0.,0.,.1505,.202,0.,0.,0.,0.,.097,.296,0.,0.,0.,0.,.0745,.384,0.,
	    0.,0.,0.,.052,.472,0.,0.,0.,0.,.044,.5245,0.,0.,0.,0.,.036,.577,
	    0.,0.,0.,0.,.0285,.6625,0.,0.,0.,0.,.021,.748,0.,0.,0.,0.,.0165,
	    .783,0.,0.,0.,0.,.012,.818,0.,0.,0.,0.,.009,.843,0.,0.,0.,0.,.006,
	    .868,0.,0.,0.,0.,.003,.8845,0.,0.,0.,0.,0.,.901,0.,0.,0.,0.,0.,
	    .903,0.,0.,0.,0.,0.,.905,0.,0.,0.,0.,0.,.9055,0.,0.,0.,0.,0.,.906,
	    0.,0.,0.,0.,0.,.92,0.,0.,0.,0.,0.,.934,0.,0.,0.,0.,0.,.952,0.,0.,
	    0.,0.,0.,.97,0.,0.,0.,0.,0.,.9815,0.,0.,0.,0.,0.,.993,0.,0.,0.,0.,
	    0.,1.,0.,0.,0.,0.,0.,.998,0.,0.,0.,0.,0.,.977,0.,0.,0.,0.,0.,.956,
	    0.,0.,0.,0.,0.,.8715,0.,0.,0.,0.,0.,.787,0.,0.,0.,0.,0.,.5775,0.,
	    0.,0.,0.,0.,.368,0.,0.,0.,0.,0.,.2435,0.,0.,0.,0.,0.,.119,0.,0.,
	    0.,0.,0.,.092,0.,0.,0.,0.,0.,.065,0.,0.,0.,0.,0.,.0555,0.,0.,0.,
	    0.,0.,.046,0.,0.,0.,0.,0.,.0385,0.,0.,0.,0.,0.,.031,0.,0.,0.,0.,
	    0.,.0255,0.,0.,0.,0.,0.,.02,0.,0.,0.,0.,0.,.016,0.,0.,0.,0.,0.,
	    .012,0.,0.,0.,0.,0.,.009,0.,0.,0.,0.,0.,.006,.002,0.,0.,0.,0.,
	    .0055,.0035,0.,0.,0.,0.,.005,.005,0.,0.,0.,0.,.004,.006,0.,0.,0.,
	    0.,.003,.007,0.,0.,0.,0.,0.,.008,0.,0.,0.,0.,0.,.009,0.,0.,0.,0.,
	    0.,.014,0.,0.,0.,0.,0.,.019,0.,0.,0.,0.,0.,.026,0.,0.,0.,0.,0.,
	    .033,0.,0.,0.,0.,0.,.052,0.,0.,0.,0.,0.,.071,0.,0.,0.,0.,0.,.1035,
	    0.,0.,0.,0.,0.,.136,0.,0.,0.,0.,0.,.2055,0.,0.,0.,0.,0.,.275,0.,
	    0.,0.,0.,0.,.3615,0.,0.,0.,0.,0.,.448,0.,0.,0.,0.,0.,.5505,0.,0.,
	    0.,0.,0.,.653,0.,0.,0.,0.,0.,.741,0.,0.,0.,0.,0.,.829,0.,0.,0.,0.,
	    0.,.8795,0.,0.,0.,0.,0.,.93,0.,0.,0.,0.,0.,.952,0.,0.,0.,0.,0.,
	    .974,0.,0.,0.,0.,0.,.987,0.,0.,0.,0.,0.,1.,0.,0.,0.,0.,0.,.9955,
	    0.,0.,0.,0.,0.,.991,0.,0.,0.,0.,0.,.9855,0.,0.,0.,0.,0.,.98,0.,0.,
	    0.,0.,0.,.9685,0.,0.,0.,0.,0.,.957,0.,0.,0.,0.,0.,.9465,0.,0.,0.,
	    0.,0.,.936,0.,0.,0.,0.,0.,.926,0.,0.,0.,0.,0.,.916,0.,0.,0.,0.,0.,
	    .9165,0.,0.,0.,0.,0.,.917,0.,0.,0.,0.,0.,.918,0.,0.,0.,0.,0.,.919,
	    0.,0.,0.,0.,0.,.9195,0.,0.,0.,0.,0.,.92,0.,0.,0.,0.,0.,.9215,0.,
	    0.,0.,0.,0.,.923,0.,0.,0.,0.,0.,.924,0.,0.,0.,0.,0.,.925,0.,0.,0.,
	    0.,0.,.916,0.,0.,0.,0.,0.,.907,0.,0.,0.,0.,0.,.8965,0.,0.,0.,0.,
	    0.,.886,0.,0.,0.,0.,0.,.8835,0.,0.,0.,0.,0.,.881,0.,0.,0.,0.,0.,
	    .8825,0.,0.,0.,0.,0.,.884,0.,0.,0.,0.,0.,.8825,0.,0.,0.,0.,0.,
	    .881,0.,0.,0.,0.,0.,.8705,0.,0.,0.,0.,0.,.86,0.,0.,0.,0.,0.,.841,
	    0.,0.,0.,0.,0.,.822,0.,0.,0.,0.,0.,.803,0.,0.,0.,0.,0.,.784,0.,0.,
	    0.,0.,0.,.7715,0.,0.,0.,0.,0.,.759,0.,0.,0.,0.,0.,.737,0.,0.,0.,
	    0.,0.,.715,0.,0.,0.,0.,0.,.5905,0.,0.,0.,0.,0.,.466,0.,0.,0.,0.,
	    0.,.3385,0.,0.,0.,0.,0.,.211,0.,0.,0.,0.,0.,.144,0.,0.,0.,0.,0.,
	    .077,0.,0.,0.,0.,0.,.054,0.,0.,0.,0.,0.,.031,0.,0.,0.,0.,0.,.023,
	    0.,0.,0.,0.,0.,.015,0.,0.,0.,0.,0.,.0115,0.,0.,0.,0.,0.,.008,0.,
	    0.,0.,0.,0.,.007,0.,0.,0.,0.,0.,.006,0.,0.,0.,0.,0.,.005,0.,0.,0.,
	    0.,0.,.004,0.,0.,0.,0.,0.,.003,0.,0.,0.,0.,0.,.002,0.,0.,0.,0.,0.,
	    .001,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,3e-4,
	    0.,0.,0.,0.,0.,7e-4,0.,0.,0.,0.,0.,.001,0.,0.,0.,0.,0.,.0013,0.,
	    0.,0.,0.,0.,.0015,0.,0.,0.,0.,0.,.0018,0.,0.,0.,0.,0.,.002,0.,0.,
	    0.,0.,0.,.0038,0.,0.,0.,0.,0.,.0055,0.,0.,0.,0.,0.,.0073,0.,0.,0.,
	    0.,0.,.009,0.,0.,0.,0.,0.,.0123,0.,0.,0.,0.,0.,.0155,0.,0.,0.,0.,
	    0.,.0188,0.,0.,0.,0.,0.,.022,0.,0.,0.,0.,0.,.0393,0.,0.,0.,0.,0.,
	    .0565,0.,0.,0.,0.,0.,.0738,0.,0.,0.,0.,0.,.091,0.,0.,0.,0.,0.,
	    .141,0.,0.,0.,0.,0.,.191,0.,0.,0.,0.,0.,.241,0.,0.,0.,0.,0.,.291,
	    0.,0.,0.,0.,0.,.3617,0.,0.,0.,0.,0.,.4325,0.,0.,0.,0.,0.,.5032,0.,
	    0.,0.,0.,0.,.574,0.,0.,0.,0.,0.,.6383,0.,0.,0.,0.,0.,.7025,0.,0.,
	    0.,0.,0.,.7668,0.,0.,0.,0.,0.,.831,0.,0.,0.,0.,0.,.8622,0.,0.,0.,
	    0.,0.,.8935,0.,0.,0.,0.,0.,.9248,0.,0.,0.,0.,0.,.956,0.,0.,0.,0.,
	    0.,.9522,0.,0.,0.,0.,0.,.9485,0.,0.,0.,0.,0.,.9447,0.,0.,0.,0.,0.,
	    .941,0.,0.,0.,0.,0.,.9417,0.,0.,0.,0.,0.,.9425,0.,0.,0.,0.,0.,
	    .9433,0.,0.,0.,0.,0.,.944,0.,0.,0.,0.,0.,.9505,0.,0.,0.,0.,0.,
	    .957,0.,0.,0.,0.,0.,.9635,0.,0.,0.,0.,0.,.97,0.,0.,0.,0.,0.,.9738,
	    0.,0.,0.,0.,0.,.9775,0.,0.,0.,0.,0.,.9813,0.,0.,0.,0.,0.,.985,0.,
	    0.,0.,0.,0.,.9833,0.,0.,0.,0.,0.,.9815,0.,0.,0.,0.,0.,.9797,0.,0.,
	    0.,0.,0.,.978,0.,0.,0.,0.,0.,.9747,0.,0.,0.,0.,0.,.9715,0.,0.,0.,
	    0.,0.,.9682,0.,0.,0.,0.,0.,.965,0.,0.,0.,0.,0.,.9682,0.,0.,0.,0.,
	    0.,.9715,0.,0.,0.,0.,0.,.9747,0.,0.,0.,0.,0.,.978,0.,0.,0.,0.,0.,
	    .9793,0.,0.,0.,0.,0.,.9805,0.,0.,0.,0.,0.,.9818,0.,0.,0.,0.,0.,
	    .983,0.,0.,0.,0.,0.,.9837,0.,0.,0.,0.,0.,.9845,0.,0.,0.,0.,0.,
	    .9852,0.,0.,0.,0.,0.,.986,0.,0.,0.,0.,0.,.9838,0.,0.,0.,0.,0.,
	    .9815,0.,0.,0.,0.,0.,.9793,0.,0.,0.,0.,0.,.977,0.,0.,0.,0.,0.,
	    .9815,0.,0.,0.,0.,0.,.986,0.,0.,0.,0.,0.,.9905,0.,0.,0.,0.,0.,
	    .995,0.,0.,0.,0.,0.,.9963,0.,0.,0.,0.,0.,.9975,0.,0.,0.,0.,0.,
	    .9988,0.,0.,0.,0.,0.,1.,0.,0.,0.,0.,0.,.9992,0.,0.,0.,0.,0.,.9985,
	    0.,0.,0.,0.,0.,.9977,0.,0.,0.,0.,0.,.997,0.,0.,0.,0.,0.,.9912,0.,
	    0.,0.,0.,0.,.9855,0.,0.,0.,0.,0.,.9797,0.,0.,0.,0.,0.,.974,0.,0.,
	    0.,0.,0.,.9697,0.,0.,0.,0.,0.,.9655,0.,0.,0.,0.,0.,.9613,0.,0.,0.,
	    0.,0.,.957,0.,0.,0.,0.,0.,.9553,0.,0.,0.,0.,0.,.9535,0.,0.,0.,0.,
	    0.,.9517,0.,0.,0.,0.,0.,.95,0.,0.,0.,0.,0.,.9505,0.,0.,0.,0.,0.,
	    .951,0.,0.,0.,0.,0.,.9515,0.,0.,0.,0.,0.,.952,0.,0.,0.,0.,0.,.937,
	    0.,0.,0.,0.,0.,.922,0.,0.,0.,0.,0.,.907,0.,0.,0.,0.,0.,.892,0.,0.,
	    0.,0.,0.,.826,0.,0.,0.,0.,0.,.76,0.,0.,0.,0.,0.,.694,0.,0.,0.,0.,
	    0.,.628,0.,0.,0.,0.,0.,.5507,0.,0.,0.,0.,0.,.4735,0.,0.,0.,0.,0.,
	    .3962,0.,0.,0.,0.,0.,.319,0.,0.,0.,0.,0.,.278,0.,0.,0.,0.,0.,.237,
	    0.,0.,0.,0.,0.,.196,0.,0.,0.,0.,0.,.155,0.,0.,0.,0.,0.,.134,0.,0.,
	    0.,0.,0.,.113,0.,0.,0.,0.,0.,.092,0.,0.,0.,0.,0.,.071,0.,0.,0.,0.,
	    0.,.0643,0.,0.,0.,0.,0.,.0575,0.,0.,0.,0.,0.,.0508,0.,0.,0.,0.,0.,
	    .044,0.,0.,0.,0.,0.,.0385,0.,0.,0.,0.,0.,.033,0.,0.,0.,0.,0.,
	    .0275,0.,0.,0.,0.,0.,.022,0.,0.,0.,0.,0.,.0197,0.,0.,0.,0.,0.,
	    .0175,0.,0.,0.,0.,0.,.0152,0.,0.,0.,0.,0.,.013,0.,0.,0.,0.,0.,
	    .012,0.,0.,0.,0.,0.,.011,0.,0.,0.,0.,0.,.01,0.,0.,0.,0.,0.,.009,
	    0.,0.,0.,0.,0.,.0077,0.,0.,0.,0.,0.,.0065,0.,0.,0.,0.,0.,.0052,0.,
	    0.,0.,0.,0.,.004,0.,0.,0.,0.,0.,.0037,0.,0.,0.,0.,0.,.0035,0.,0.,
	    0.,0.,0.,.0032,0.,0.,0.,0.,0.,.003,0.,0.,0.,0.,0.,.0027,0.,0.,0.,
	    0.,0.,.0025,0.,0.,0.,0.,0.,.0022,0.,0.,0.,0.,0.,.002,0.,0.,0.,0.,
	    0.,.0015,0.,0.,0.,0.,0.,.001,0.,0.,0.,0.,0.,5e-4,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,5e-4,0.,
	    0.,0.,0.,0.,.001,0.,0.,0.,0.,0.,.0015,0.,0.,0.,0.,0.,.002,0.,0.,
	    0.,0.,0.,.0025,0.,0.,0.,0.,0.,.003,0.,0.,0.,0.,0.,.0035,0.,0.,0.,
	    0.,0.,.004,0.,0.,0.,0.,0.,.0043,0.,0.,0.,0.,0.,.0045,0.,0.,0.,0.,
	    0.,.0048,0.,0.,0.,0.,0.,.005,0.,0.,0.,0.,0.,.0055,0.,0.,0.,0.,0.,
	    .006,0.,0.,0.,0.,0.,.0065,0.,0.,0.,0.,0.,.007,0.,0.,0.,0.,0.,
	    .0075,0.,0.,0.,0.,0.,.008,0.,0.,0.,0.,0.,.0085,0.,0.,0.,0.,0.,
	    .009,0.,0.,0.,0.,0.,.0103,0.,0.,0.,0.,0.,.0115,0.,0.,0.,0.,0.,
	    .0128,0.,0.,0.,0.,0.,.014,0.,0.,0.,0.,0.,.0153,0.,0.,0.,0.,0.,
	    .0165,0.,0.,0.,0.,0.,.0178,0.,0.,0.,0.,0.,.019,0.,0.,0.,0.,0.,
	    .0233,0.,0.,0.,0.,0.,.0275,0.,0.,0.,0.,0.,.0318,0.,0.,0.,0.,0.,
	    .036,0.,0.,0.,0.,0.,.04,0.,0.,0.,0.,0.,.044,0.,0.,0.,0.,0.,.048,
	    0.,0.,0.,0.,0.,.052,0.,0.,0.,0.,0.,.0563,0.,0.,0.,0.,0.,.0605,0.,
	    0.,0.,0.,0.,.0648,0.,0.,0.,0.,0.,.069,0.,0.,0.,0.,0.,.0768,0.,0.,
	    0.,0.,0.,.0845,0.,0.,0.,0.,0.,.0923,0.,0.,0.,0.,0.,.1,0.,0.,0.,0.,
	    0.,.1125,0.,0.,0.,0.,0.,.125,0.,0.,0.,0.,0.,.1375,0.,0.,0.,0.,0.,
	    .15,0.,0.,0.,0.,0.,.1753,0.,0.,0.,0.,0.,.2005,0.,0.,0.,0.,0.,
	    .2258,0.,0.,0.,0.,0.,.251,0.,0.,0.,0.,0.,.287,0.,0.,0.,0.,0.,.323,
	    0.,0.,0.,0.,0.,.359,0.,0.,0.,0.,0.,.395,0.,0.,0.,0.,0.,.4313,0.,
	    0.,0.,0.,0.,.4675,0.,0.,0.,0.,0.,.5038,0.,0.,0.,0.,0.,.54,0.,0.,
	    0.,0.,0.,.5788,0.,0.,0.,0.,0.,.6175,0.,0.,0.,0.,0.,.6563,0.,0.,0.,
	    0.,0.,.695,0.,0.,0.,0.,0.,.7345,0.,0.,0.,0.,0.,.774,0.,0.,0.,0.,
	    0.,.8135,0.,0.,0.,0.,0.,.853,0.,0.,0.,0.,0.,.8737,0.,0.,0.,0.,0.,
	    .8945,0.,0.,0.,0.,0.,.9152,0.,0.,0.,0.,0.,.936,0.,0.,0.,0.,0.,
	    .9398,0.,0.,0.,0.,0.,.9435,0.,0.,0.,0.,0.,.9473,0.,0.,0.,0.,0.,
	    .951,0.,0.,0.,0.,0.,.9472,0.,0.,0.,0.,0.,.9435,0.,0.,0.,0.,0.,
	    .9397,0.,0.,0.,0.,0.,.936,0.,0.,0.,0.,0.,.9385,0.,0.,0.,0.,0.,
	    .941,0.,0.,0.,0.,0.,.9435,0.,0.,0.,0.,0.,.946,0.,0.,0.,0.,0.,.95,
	    0.,0.,0.,0.,0.,.954,0.,0.,0.,0.,0.,.958,0.,0.,0.,0.,0.,.962,0.,0.,
	    0.,0.,0.,.9693,0.,0.,0.,0.,0.,.9765,0.,0.,0.,0.,0.,.9838,0.,0.,0.,
	    0.,0.,.991,0.,0.,0.,0.,0.,.993,0.,0.,0.,0.,0.,.995,0.,0.,0.,0.,0.,
	    .997,0.,0.,0.,0.,0.,.999,0.,0.,0.,0.,0.,1.,0.,0.,0.,0.,0.,.9988,
	    0.,0.,0.,0.,0.,.9975,0.,0.,0.,0.,0.,.996,0.,0.,0.,0.,0.,.9952,0.,
	    0.,0.,0.,0.,.9945,0.,0.,0.,0.,0.,.9937,0.,0.,0.,0.,0.,.993,0.,0.,
	    0.,0.,0.,.9922,0.,0.,0.,0.,0.,.9915,0.,0.,0.,0.,0.,.9908,0.,0.,0.,
	    0.,0.,.99,0.,0.,0.,0.,0.,.9815,0.,0.,0.,0.,0.,.973,0.,0.,0.,0.,0.,
	    .9645,0.,0.,0.,0.,0.,.956,0.,0.,0.,0.,0.,.9525,0.,0.,0.,0.,0.,
	    .949,0.,0.,0.,0.,0.,.9455,0.,0.,0.,0.,0.,.942,0.,0.,0.,0.,0.,.937,
	    0.,0.,0.,0.,0.,.932,0.,0.,0.,0.,0.,.927,0.,0.,0.,0.,0.,.922,0.,0.,
	    0.,0.,0.,.9205,0.,0.,0.,0.,0.,.919,0.,0.,0.,0.,0.,.9175,0.,0.,0.,
	    0.,0.,.916,0.,0.,0.,0.,0.,.9135,0.,0.,0.,0.,0.,.911,0.,0.,0.,0.,
	    0.,.9085,0.,0.,0.,0.,0.,.906,0.,0.,0.,0.,0.,.902,0.,0.,0.,0.,0.,
	    .898,0.,0.,0.,0.,0.,.894,0.,0.,0.,0.,0.,.89,0.,0.,0.,0.,0.,.873,
	    0.,0.,0.,0.,0.,.856,0.,0.,0.,0.,0.,.839,0.,0.,0.,0.,0.,.822,0.,0.,
	    0.,0.,0.,.8058,0.,0.,0.,0.,0.,.7895,0.,0.,0.,0.,0.,.7732,0.,0.,0.,
	    0.,0.,.757,0.,0.,0.,0.,0.,.7545,0.,0.,0.,0.,0.,.752,0.,0.,0.,0.,
	    0.,.7495,0.,0.,0.,0.,0.,.747,0.,0.,0.,0.,0.,.7623,0.,0.,0.,0.,0.,
	    .7775,0.,0.,0.,0.,0.,.7928,0.,0.,0.,0.,0.,.808,0.,0.,0.,0.,0.,
	    .8245,0.,0.,0.,0.,0.,.841,0.,0.,0.,0.,0.,.8575,0.,0.,0.,0.,0.,
	    .874,0.,0.,0.,0.,0.,.8292,0.,0.,0.,0.,0.,.7845,0.,0.,0.,0.,0.,
	    .7397,0.,0.,0.,0.,0.,.695,0.,0.,0.,0.,0.,.629,0.,0.,0.,0.,0.,.563,
	    0.,0.,0.,0.,0.,.497,0.,0.,0.,0.,0.,.431,0.,0.,0.,0.,0.,.3747,0.,
	    0.,0.,0.,0.,.3185,0.,0.,0.,0.,0.,.2622,0.,0.,0.,0.,0.,.206,0.,0.,
	    0.,0.,0.,.1735,0.,0.,0.,0.,0.,.141,0.,0.,0.,0.,0.,.1085,0.,0.,0.,
	    0.,0.,.076,0.,0.,0.,0.,0.,.0653,0.,0.,0.,0.,0.,.0545,0.,0.,0.,0.,
	    0.,.0438,0.,0.,0.,0.,0.,.033,0.,0.,0.,0.,0.,.0275,0.,0.,0.,0.,0.,
	    .022,0.,0.,0.,0.,0.,.0165,0.,0.,0.,0.,0.,.011,0.,0.,0.,0.,0.,
	    .0097,0.,0.,0.,0.,0.,.0085,0.,0.,0.,0.,0.,.0072,0.,0.,0.,0.,0.,
	    .006,0.,0.,0.,0.,0.,.0045,0.,0.,0.,0.,0.,.003,0.,0.,0.,0.,0.,
	    .0015,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };

    integer i__;
    doublereal wli[6], wls[6];

/*<       real s,wlinf,wlsup >*/
/*<       common /sixs_ffu/ s(1501),wlinf,wlsup >*/
/*<       real sr(6,1501),wli(6),wls(6) >*/
/*<       integer iwa,l,i >*/
/*    1st spectral band of thematic mapper */
/*<    >*/

/*    2nd spectral band of thematic mapper */
/*<    >*/

/*    3rd spectral band of thematic mapper */
/*<    >*/

/*    4th spectral band of thematic mapper */
/*<    >*/

/*    5th spectral band of thematic mapper */
/*<    >*/
/*<    >*/

/*    7th spectral band of thematic mapper */
/*<    >*/
/*<    >*/
/*<       wli(1)=0.43 >*/
    wli[0] = .43;
/*<       wls(1)=0.56 >*/
    wls[0] = .56;
/*<       wli(2)=0.5 >*/
    wli[1] = .5;
/*<       wls(2)=0.6499999 >*/
    wls[1] = .6499999;
/*<       wli(3)=0.5799999 >*/
    wli[2] = .5799999;
/*<       wls(3)=0.74 >*/
    wls[2] = .74;
/*<       wli(4)=0.73 >*/
    wli[3] = .73;
/*<       wls(4)=.95 >*/
    wls[3] = .95;
/*<       wli(5)=1.5025 >*/
    wli[4] = 1.5025;
/*<       wls(5)=1.89 >*/
    wls[4] = 1.89;
/*<       wli(6)=1.95 >*/
    wli[5] = 1.95;
/*<       wls(6)=2.41 >*/
    wls[5] = 2.41;
/*<       do 1 i=1,1501 >*/
    for (i__ = 1; i__ <= 1501; ++i__) {
/*<       s(i)=sr(iwa,i) >*/
	sixs_ffu__1.s[i__ - 1] = sr[*iwa + i__ * 6 - 7];
/*<     1 continue >*/
/* L1: */
    }
/*<       wlinf=wli(iwa) >*/
    sixs_ffu__1.wlinf = wli[*iwa - 1];
/*<       wlsup=wls(iwa) >*/
    sixs_ffu__1.wlsup = wls[*iwa - 1];
/*<       return >*/
    return 0;
/*<       end >*/
} /* tm_ */

#ifdef __cplusplus
	}
#endif
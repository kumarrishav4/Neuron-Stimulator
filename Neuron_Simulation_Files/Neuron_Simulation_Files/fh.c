/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__fh
#define _nrn_initial _nrn_initial__fh
#define nrn_cur _nrn_cur__fh
#define _nrn_current _nrn_current__fh
#define nrn_jacob _nrn_jacob__fh
#define nrn_state _nrn_state__fh
#define _net_receive _net_receive__fh 
#define mhnp mhnp__fh 
#define states states__fh 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define pnabar _p[0]
#define pnabar_columnindex 0
#define ppbar _p[1]
#define ppbar_columnindex 1
#define pkbar _p[2]
#define pkbar_columnindex 2
#define gl _p[3]
#define gl_columnindex 3
#define el _p[4]
#define el_columnindex 4
#define ip _p[5]
#define ip_columnindex 5
#define il _p[6]
#define il_columnindex 6
#define m _p[7]
#define m_columnindex 7
#define h _p[8]
#define h_columnindex 8
#define n _p[9]
#define n_columnindex 9
#define p _p[10]
#define p_columnindex 10
#define nai _p[11]
#define nai_columnindex 11
#define nao _p[12]
#define nao_columnindex 12
#define ki _p[13]
#define ki_columnindex 13
#define ko _p[14]
#define ko_columnindex 14
#define Dm _p[15]
#define Dm_columnindex 15
#define Dh _p[16]
#define Dh_columnindex 16
#define Dn _p[17]
#define Dn_columnindex 17
#define Dp _p[18]
#define Dp_columnindex 18
#define ina _p[19]
#define ina_columnindex 19
#define ik _p[20]
#define ik_columnindex 20
#define _g _p[21]
#define _g_columnindex 21
#define _ion_nai	*_ppvar[0]._pval
#define _ion_nao	*_ppvar[1]._pval
#define _ion_ina	*_ppvar[2]._pval
#define _ion_dinadv	*_ppvar[3]._pval
#define _ion_ki	*_ppvar[4]._pval
#define _ion_ko	*_ppvar[5]._pval
#define _ion_ik	*_ppvar[6]._pval
#define _ion_dikdv	*_ppvar[7]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alp(void);
 static void _hoc_bet(void);
 static void _hoc_expM1(void);
 static void _hoc_efun(void);
 static void _hoc_ghk(void);
 static void _hoc_mhnp(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_fh", _hoc_setdata,
 "alp_fh", _hoc_alp,
 "bet_fh", _hoc_bet,
 "expM1_fh", _hoc_expM1,
 "efun_fh", _hoc_efun,
 "ghk_fh", _hoc_ghk,
 "mhnp_fh", _hoc_mhnp,
 0, 0
};
#define alp alp_fh
#define bet bet_fh
#define expM1 expM1_fh
#define efun efun_fh
#define ghk ghk_fh
 extern double alp( double , double );
 extern double bet( double , double );
 extern double expM1( double , double );
 extern double efun( double );
 extern double ghk( double , double , double );
 /* declare global and static user variables */
#define inf inf_fh
 double inf[4];
#define tau tau_fh
 double tau[4];
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tau_fh", "ms",
 "pnabar_fh", "cm/s",
 "ppbar_fh", "cm/s",
 "pkbar_fh", "cm/s",
 "gl_fh", "mho/cm2",
 "el_fh", "mV",
 "ip_fh", "mA/cm2",
 "il_fh", "mA/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double p0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "inf_fh", inf_fh, 4,
 "tau_fh", tau_fh, 4,
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[8]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"fh",
 "pnabar_fh",
 "ppbar_fh",
 "pkbar_fh",
 "gl_fh",
 "el_fh",
 0,
 "ip_fh",
 "il_fh",
 0,
 "m_fh",
 "h_fh",
 "n_fh",
 "p_fh",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 22, _prop);
 	/*initialize range parameters*/
 	pnabar = 0.00732;
 	ppbar = 5.5e-05;
 	pkbar = 0.000288;
 	gl = 0.0614;
 	el = -78;
 	_prop->param = _p;
 	_prop->param_size = 22;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 9, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* nai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* nao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[4]._pval = &prop_ion->param[1]; /* ki */
 	_ppvar[5]._pval = &prop_ion->param[2]; /* ko */
 	_ppvar[6]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[7]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _fh_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 22, 9);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 fh fh.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x1.78e555060882cp+16, 96485.3}; /* 96485.3321233100141 */
 
#define R _nrnunit_R[_nrnunit_use_legacy_]
static double _nrnunit_R[2] = {0x1.0a1013e8990bep+3, 8.3145}; /* 8.3144626181532395 */
static int _reset;
static char *modelname = "FH channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int mhnp(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[4], _dlist1[4];
 static int states(_threadargsproto_);
 
double ghk (  double _lv , double _lci , double _lco ) {
   double _lghk;
 double _lz , _leci , _leco ;
 _lz = ( 1e-3 ) * FARADAY * _lv / ( R * ( celsius + 273.15 ) ) ;
   _leco = _lco * efun ( _threadargscomma_ _lz ) ;
   _leci = _lci * efun ( _threadargscomma_ - _lz ) ;
   _lghk = ( .001 ) * FARADAY * ( _leci - _leco ) ;
   
return _lghk;
 }
 
static void _hoc_ghk(void) {
  double _r;
   _r =  ghk (  *getarg(1) , *getarg(2) , *getarg(3) );
 hoc_retpushx(_r);
}
 
double efun (  double _lz ) {
   double _lefun;
 if ( fabs ( _lz ) < 1e-4 ) {
     _lefun = 1.0 - _lz / 2.0 ;
     }
   else {
     _lefun = _lz / ( exp ( _lz ) - 1.0 ) ;
     }
   
return _lefun;
 }
 
static void _hoc_efun(void) {
  double _r;
   _r =  efun (  *getarg(1) );
 hoc_retpushx(_r);
}
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   mhnp ( _threadargscomma_ v * 1.0 ) ;
   Dm = ( inf [ 0 ] - m ) / tau [ 0 ] ;
   Dh = ( inf [ 1 ] - h ) / tau [ 1 ] ;
   Dn = ( inf [ 2 ] - n ) / tau [ 2 ] ;
   Dp = ( inf [ 3 ] - p ) / tau [ 3 ] ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 mhnp ( _threadargscomma_ v * 1.0 ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[0] )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[1] )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[2] )) ;
 Dp = Dp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[3] )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   mhnp ( _threadargscomma_ v * 1.0 ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[0])))*(- ( ( ( inf[0] ) ) / tau[0] ) / ( ( ( ( - 1.0 ) ) ) / tau[0] ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[1])))*(- ( ( ( inf[1] ) ) / tau[1] ) / ( ( ( ( - 1.0 ) ) ) / tau[1] ) - h) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[2])))*(- ( ( ( inf[2] ) ) / tau[2] ) / ( ( ( ( - 1.0 ) ) ) / tau[2] ) - n) ;
    p = p + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[3])))*(- ( ( ( inf[3] ) ) / tau[3] ) / ( ( ( ( - 1.0 ) ) ) / tau[3] ) - p) ;
   }
  return 0;
}
 
double alp (  double _lv , double _li ) {
   double _lalp;
 double _la , _lb , _lc , _lq10 ;
 _lv = _lv + 78.0 ;
   if ( _li  == 0.0 ) {
     _la = .49 ;
     _lb = 25.41 ;
     _lc = 6.06 ;
     _lq10 = pow( 2.2 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lb - _lv , _lc ) ;
     }
   else if ( _li  == 1.0 ) {
     _la = 0.09 ;
     _lb = - 27.74 ;
     _lc = 9.06 ;
     _lq10 = pow( 2.9 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   else if ( _li  == 2.0 ) {
     _la = .02 ;
     _lb = 35.0 ;
     _lc = 10.0 ;
     _lq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lb - _lv , _lc ) ;
     }
   else {
     _la = .00092 ;
     _lb = - 25.75 ;
     _lc = 15.73 ;
     _lq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lb - _lv , _lc ) ;
     }
   
return _lalp;
 }
 
static void _hoc_alp(void) {
  double _r;
   _r =  alp (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double bet (  double _lv , double _li ) {
   double _lbet;
 double _la , _lb , _lc , _lq10 ;
 _lv = _lv + 78.0 ;
   if ( _li  == 0.0 ) {
     _la = 1.04 ;
     _lb = 21. ;
     _lc = 9.41 ;
     _lq10 = pow( 2.2 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lbet = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   else if ( _li  == 1.0 ) {
     _la = 3.7 ;
     _lb = 56. ;
     _lc = 12.5 ;
     _lq10 = pow( 2.9 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lbet = _lq10 * _la / ( exp ( ( _lb - _lv ) / _lc ) + 1.0 ) ;
     }
   else if ( _li  == 2.0 ) {
     _la = 0.05 ;
     _lb = 10.0 ;
     _lc = 10.0 ;
     _lq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lbet = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   else {
     _la = .0042 ;
     _lb = 0.24 ;
     _lc = 8.54 ;
     _lq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
     _lbet = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   
return _lbet;
 }
 
static void _hoc_bet(void) {
  double _r;
   _r =  bet (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double expM1 (  double _lx , double _ly ) {
   double _lexpM1;
 if ( fabs ( _lx / _ly ) < 1e-6 ) {
     _lexpM1 = _ly * ( 1.0 - _lx / _ly / 2.0 ) ;
     }
   else {
     _lexpM1 = _lx / ( exp ( _lx / _ly ) - 1.0 ) ;
     }
   
return _lexpM1;
 }
 
static void _hoc_expM1(void) {
  double _r;
   _r =  expM1 (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
static int  mhnp (  double _lv ) {
   double _la , _lb ;
 {int  _li ;for ( _li = 0 ; _li <= 3 ; _li ++ ) {
     _la = alp ( _threadargscomma_ _lv , ((double) _li ) ) ;
     _lb = bet ( _threadargscomma_ _lv , ((double) _li ) ) ;
     tau [ _li ] = 1.0 / ( _la + _lb ) ;
     inf [ _li ] = _la / ( _la + _lb ) ;
     } }
    return 0; }
 
static void _hoc_mhnp(void) {
  double _r;
   _r = 1.;
 mhnp (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
     _ode_spec1 ();
   }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 3, 4);
   nrn_update_ion_pointer(_k_sym, _ppvar, 4, 1);
   nrn_update_ion_pointer(_k_sym, _ppvar, 5, 2);
   nrn_update_ion_pointer(_k_sym, _ppvar, 6, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 7, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  h = h0;
  m = m0;
  n = n0;
  p = p0;
 {
   mhnp ( _threadargscomma_ v * 1.0 ) ;
   m = inf [ 0 ] ;
   h = inf [ 1 ] ;
   n = inf [ 2 ] ;
   p = inf [ 3 ] ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 initmodel();
  }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   double _lghkna ;
 _lghkna = ghk ( _threadargscomma_ v , nai , nao ) ;
   ina = pnabar * m * m * h * _lghkna ;
   ip = 0.0 * ppbar * p * p * ghk ( _threadargscomma_ v , ki , ko ) ;
   ik = pkbar * n * n * ghk ( _threadargscomma_ v , ki , ko ) ;
   il = gl * ( v - el ) ;
   }
 _current += ina;
 _current += ik;
 _current += il;
 _current += ip;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 { error =  states();
 if(error){fprintf(stderr,"at line 58 in file fh.mod:\n	SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 }  }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = m_columnindex;  _dlist1[0] = Dm_columnindex;
 _slist1[1] = h_columnindex;  _dlist1[1] = Dh_columnindex;
 _slist1[2] = n_columnindex;  _dlist1[2] = Dn_columnindex;
 _slist1[3] = p_columnindex;  _dlist1[3] = Dp_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "fh.mod";
static const char* nmodl_file_text = 
  "TITLE FH channel\n"
  ": Frankenhaeuser - Huxley channels for Xenopus\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX fh\n"
  "	USEION na READ nai, nao WRITE ina\n"
  "	USEION k READ ki, ko WRITE ik\n"
  "	NONSPECIFIC_CURRENT il, ip\n"
  "	RANGE pnabar, pkbar, ppbar, gl, el, il, ip\n"
  "	GLOBAL inf,tau\n"
  "}\n"
  "\n"
  "\n"
  "UNITS {\n"
  "	(molar) = (/liter)\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(mM) = (millimolar)\n"
  "	FARADAY = (faraday) (coulomb)\n"
  "	R = (k-mole) (joule/degC)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	v (mV)\n"
  "	celsius (degC) : 37\n"
  "	pnabar=7.32e-3 (cm/s)\n"
  "	ppbar=.055e-3 (cm/s)\n"
  "	pkbar=0.288e-3 (cm/s)\n"
  "	nai (mM) : 8.71\n"
  "	nao (mM) : 154\n"
  "	ki (mM) : 155\n"
  "	ko (mM) : 5.9\n"
  "	gl=61.4e-3 (mho/cm2)\n"
  "	el = -78(mV)\n"
  "}\n"
  "STATE {\n"
  "	m h n p\n"
  "}\n"
  "ASSIGNED {\n"
  "	ina (mA/cm2)\n"
  "	ik (mA/cm2)\n"
  "	ip (mA/cm2)\n"
  "	il (mA/cm2)\n"
  "	inf[4]\n"
  "	tau[4] (ms)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	mhnp(v*1(/mV))\n"
  "	m = inf[0]\n"
  "	h = inf[1]\n"
  "	n = inf[2]\n"
  "	p = inf[3]\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	LOCAL ghkna\n"
  "	SOLVE states METHOD cnexp\n"
  "	ghkna = ghk(v, nai, nao)\n"
  "	ina = pnabar*m*m*h*ghkna\n"
  "	ip = 0*ppbar*p*p*ghk(v, ki, ko)\n"
  "	ik = pkbar*n*n*ghk(v, ki, ko)\n"
  "	il = gl*(v - el)\n"
  "}\n"
  "\n"
  "FUNCTION ghk(v(mV), ci(mM), co(mM)) (.001 coul/cm3) {\n"
  "	:assume a single charge\n"
  "	LOCAL z, eci, eco\n"
  "	z = (1e-3)*FARADAY*v/(R*(celsius+273.15))\n"
  "	eco = co*efun(z)\n"
  "	eci = ci*efun(-z)\n"
  "	ghk = (.001)*FARADAY*(eci - eco)\n"
  "}\n"
  "\n"
  "FUNCTION efun(z) {\n"
  "	if (fabs(z) < 1e-4) {\n"
  "		efun = 1 - z/2\n"
  "	}else{\n"
  "		efun = z/(exp(z) - 1)\n"
  "	}\n"
  "}\n"
  "\n"
  "DERIVATIVE states {	: exact when v held constant\n"
  "	mhnp(v*1(/mV))\n"
  "	m' = (inf[0] - m)/tau[0]\n"
  "	h' = (inf[1] - h)/tau[1]\n"
  "	n' = (inf[2] - n)/tau[2]\n"
  "	p' = (inf[3] - p)/tau[3]\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "FUNCTION alp(v(mV),i) { LOCAL a,b,c,q10 :rest = -78  order m,h,n,p\n"
  "	v = v+78	\n"
  "	if (i==0) {\n"
  "		a=.49 b=25.41 c=6.06\n"
  "		q10 = 2.2^((celsius - 20)/10)\n"
  "		alp = q10*a*expM1(b - v, c)\n"
  "	}else if (i==1){\n"
  "		a=0.09 b=-27.74 c=9.06\n"
  "		q10 = 2.9^((celsius - 20)/10)\n"
  "		alp = q10*a*expM1(v - b, c)\n"
  "	}else if (i==2){\n"
  "		a=.02 b= 35 c=10\n"
  "		q10 = 3^((celsius - 20)/10)\n"
  "		alp = q10*a*expM1(b - v, c)\n"
  "	}else{\n"
  "		a=.00092 b= -25.75 c=15.73\n"
  "		q10 = 3^((celsius - 20)/10)\n"
  "		alp = q10*a*expM1(b - v , c)\n"
  "	}\n"
  "}\n"
  "\n"
  "FUNCTION bet(v,i) { LOCAL a,b,c,q10 :rest = -78  order m,h,n,p\n"
  "	v = v+78\n"
  "	if (i==0) {\n"
  "		a=1.04  b= 21.  c=9.41\n"
  "		q10 = 2.2^((celsius - 20)/10)\n"
  "		bet = q10*a*expM1(v - b, c)\n"
  "	}else if (i==1){\n"
  "		a=3.7  b= 56.  c=12.5\n"
  "		q10 = 2.9^((celsius - 20)/10)\n"
  "		bet = q10*a/(exp((b - v)/c) + 1)\n"
  "	}else if (i==2){\n"
  "		a=0.05  b= 10  c=10\n"
  "		q10 = 3^((celsius - 20)/10)\n"
  "		bet = q10*a*expM1(v - b, c)\n"
  "	}else{\n"
  "		a=.0042 b= 0.24 c=8.54\n"
  "		q10 = 3^((celsius - 20)/10)\n"
  "		bet = q10*a*expM1(v - b, c)\n"
  "	}\n"
  "}\n"
  "\n"
  "FUNCTION expM1(x,y) {\n"
  "	if (fabs(x/y) < 1e-6) {\n"
  "		expM1 = y*(1 - x/y/2)\n"
  "	}else{\n"
  "		expM1 = x/(exp(x/y) - 1)\n"
  "	}\n"
  "}\n"
  "\n"
  "PROCEDURE mhnp(v) {LOCAL a, b :rest = -78	TABLE inf, tau DEPEND celsius FROM -100 TO 100 WITH 200\n"
  "	FROM i=0 TO 3 {\n"
  "		a = alp(v,i)  b=bet(v,i)\n"
  "		tau[i] = 1/(a + b)\n"
  "		inf[i] = a/(a + b)\n"
  "	}\n"
  "}\n"
  "UNITSON\n"
  ;
#endif

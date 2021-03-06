/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ASK1_H_RPCGEN
#define _ASK1_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct Y_array {
	struct {
		u_int y_array_len;
		int *y_array_val;
	} y_array;
	int y_size;
};
typedef struct Y_array Y_array;

struct prod_array {
	struct {
		u_int y_array_len;
		int *y_array_val;
	} y_array;
	int y_size;
	float a;
};
typedef struct prod_array prod_array;

struct max_min {
	int max;
	int min;
};
typedef struct max_min max_min;

struct aY {
	struct {
		u_int prod_len;
		float *prod_val;
	} prod;
};
typedef struct aY aY;

#define ASK1 0x23451111
#define ASK1_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define AVG 1
extern  float * avg_1(Y_array *, CLIENT *);
extern  float * avg_1_svc(Y_array *, struct svc_req *);
#define MAX_MIN 2
extern  max_min * max_min_1(Y_array *, CLIENT *);
extern  max_min * max_min_1_svc(Y_array *, struct svc_req *);
#define MUL 3
extern  aY * mul_1(prod_array *, CLIENT *);
extern  aY * mul_1_svc(prod_array *, struct svc_req *);
extern int ask1_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define AVG 1
extern  float * avg_1();
extern  float * avg_1_svc();
#define MAX_MIN 2
extern  max_min * max_min_1();
extern  max_min * max_min_1_svc();
#define MUL 3
extern  aY * mul_1();
extern  aY * mul_1_svc();
extern int ask1_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_Y_array (XDR *, Y_array*);
extern  bool_t xdr_prod_array (XDR *, prod_array*);
extern  bool_t xdr_max_min (XDR *, max_min*);
extern  bool_t xdr_aY (XDR *, aY*);

#else /* K&R C */
extern bool_t xdr_Y_array ();
extern bool_t xdr_prod_array ();
extern bool_t xdr_max_min ();
extern bool_t xdr_aY ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ASK1_H_RPCGEN */

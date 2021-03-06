/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ADMIN_PROTOCOL_H_RPCGEN
#define _ADMIN_PROTOCOL_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#include <libvirt/libvirt-admin.h>
#include "virxdrdefs.h"
#define ADMIN_STRING_MAX 4194304
#define ADMIN_SERVER_LIST_MAX 16384
#define ADMIN_SERVER_THREADPOOL_PARAMETERS_MAX 32
#define ADMIN_CLIENT_LIST_MAX 16384
#define ADMIN_CLIENT_INFO_PARAMETERS_MAX 64
#define ADMIN_SERVER_CLIENT_LIMITS_MAX 32

typedef char *admin_nonnull_string;

typedef admin_nonnull_string *admin_string;

struct admin_typed_param_value {
        int type;
        union {
                int i;
                u_int ui;
                int64_t l;
                uint64_t ul;
                double d;
                int b;
                admin_nonnull_string s;
        } admin_typed_param_value_u;
};
typedef struct admin_typed_param_value admin_typed_param_value;

struct admin_typed_param {
        admin_nonnull_string field;
        admin_typed_param_value value;
};
typedef struct admin_typed_param admin_typed_param;

struct admin_nonnull_server {
        admin_nonnull_string name;
};
typedef struct admin_nonnull_server admin_nonnull_server;

struct admin_nonnull_client {
        admin_nonnull_server srv;
        uint64_t id;
        int64_t timestamp;
        u_int transport;
};
typedef struct admin_nonnull_client admin_nonnull_client;

struct admin_connect_open_args {
        u_int flags;
};
typedef struct admin_connect_open_args admin_connect_open_args;

struct admin_connect_get_lib_version_ret {
        uint64_t libVer;
};
typedef struct admin_connect_get_lib_version_ret admin_connect_get_lib_version_ret;

struct admin_connect_list_servers_args {
        u_int need_results;
        u_int flags;
};
typedef struct admin_connect_list_servers_args admin_connect_list_servers_args;

struct admin_connect_list_servers_ret {
        struct {
                u_int servers_len;
                admin_nonnull_server *servers_val;
        } servers;
        u_int ret;
};
typedef struct admin_connect_list_servers_ret admin_connect_list_servers_ret;

struct admin_connect_lookup_server_args {
        admin_nonnull_string name;
        u_int flags;
};
typedef struct admin_connect_lookup_server_args admin_connect_lookup_server_args;

struct admin_connect_lookup_server_ret {
        admin_nonnull_server srv;
};
typedef struct admin_connect_lookup_server_ret admin_connect_lookup_server_ret;

struct admin_server_get_threadpool_parameters_args {
        admin_nonnull_server srv;
        u_int flags;
};
typedef struct admin_server_get_threadpool_parameters_args admin_server_get_threadpool_parameters_args;

struct admin_server_get_threadpool_parameters_ret {
        struct {
                u_int params_len;
                admin_typed_param *params_val;
        } params;
};
typedef struct admin_server_get_threadpool_parameters_ret admin_server_get_threadpool_parameters_ret;

struct admin_server_set_threadpool_parameters_args {
        admin_nonnull_server srv;
        struct {
                u_int params_len;
                admin_typed_param *params_val;
        } params;
        u_int flags;
};
typedef struct admin_server_set_threadpool_parameters_args admin_server_set_threadpool_parameters_args;

struct admin_server_list_clients_args {
        admin_nonnull_server srv;
        u_int need_results;
        u_int flags;
};
typedef struct admin_server_list_clients_args admin_server_list_clients_args;

struct admin_server_list_clients_ret {
        struct {
                u_int clients_len;
                admin_nonnull_client *clients_val;
        } clients;
        u_int ret;
};
typedef struct admin_server_list_clients_ret admin_server_list_clients_ret;

struct admin_server_lookup_client_args {
        admin_nonnull_server srv;
        uint64_t id;
        u_int flags;
};
typedef struct admin_server_lookup_client_args admin_server_lookup_client_args;

struct admin_server_lookup_client_ret {
        admin_nonnull_client clnt;
};
typedef struct admin_server_lookup_client_ret admin_server_lookup_client_ret;

struct admin_client_get_info_args {
        admin_nonnull_client clnt;
        u_int flags;
};
typedef struct admin_client_get_info_args admin_client_get_info_args;

struct admin_client_get_info_ret {
        struct {
                u_int params_len;
                admin_typed_param *params_val;
        } params;
};
typedef struct admin_client_get_info_ret admin_client_get_info_ret;

struct admin_client_close_args {
        admin_nonnull_client clnt;
        u_int flags;
};
typedef struct admin_client_close_args admin_client_close_args;

struct admin_server_get_client_limits_args {
        admin_nonnull_server srv;
        u_int flags;
};
typedef struct admin_server_get_client_limits_args admin_server_get_client_limits_args;

struct admin_server_get_client_limits_ret {
        struct {
                u_int params_len;
                admin_typed_param *params_val;
        } params;
};
typedef struct admin_server_get_client_limits_ret admin_server_get_client_limits_ret;

struct admin_server_set_client_limits_args {
        admin_nonnull_server srv;
        struct {
                u_int params_len;
                admin_typed_param *params_val;
        } params;
        u_int flags;
};
typedef struct admin_server_set_client_limits_args admin_server_set_client_limits_args;

struct admin_connect_get_logging_outputs_args {
        u_int flags;
};
typedef struct admin_connect_get_logging_outputs_args admin_connect_get_logging_outputs_args;

struct admin_connect_get_logging_outputs_ret {
        admin_nonnull_string outputs;
        u_int noutputs;
};
typedef struct admin_connect_get_logging_outputs_ret admin_connect_get_logging_outputs_ret;

struct admin_connect_get_logging_filters_args {
        u_int flags;
};
typedef struct admin_connect_get_logging_filters_args admin_connect_get_logging_filters_args;

struct admin_connect_get_logging_filters_ret {
        admin_string filters;
        u_int nfilters;
};
typedef struct admin_connect_get_logging_filters_ret admin_connect_get_logging_filters_ret;

struct admin_connect_set_logging_outputs_args {
        admin_string outputs;
        u_int flags;
};
typedef struct admin_connect_set_logging_outputs_args admin_connect_set_logging_outputs_args;

struct admin_connect_set_logging_filters_args {
        admin_string filters;
        u_int flags;
};
typedef struct admin_connect_set_logging_filters_args admin_connect_set_logging_filters_args;
#define ADMIN_PROGRAM 0x06900690
#define ADMIN_PROTOCOL_VERSION 1

enum admin_procedure {
        ADMIN_PROC_CONNECT_OPEN = 1,
        ADMIN_PROC_CONNECT_CLOSE = 2,
        ADMIN_PROC_CONNECT_GET_LIB_VERSION = 3,
        ADMIN_PROC_CONNECT_LIST_SERVERS = 4,
        ADMIN_PROC_CONNECT_LOOKUP_SERVER = 5,
        ADMIN_PROC_SERVER_GET_THREADPOOL_PARAMETERS = 6,
        ADMIN_PROC_SERVER_SET_THREADPOOL_PARAMETERS = 7,
        ADMIN_PROC_SERVER_LIST_CLIENTS = 8,
        ADMIN_PROC_SERVER_LOOKUP_CLIENT = 9,
        ADMIN_PROC_CLIENT_GET_INFO = 10,
        ADMIN_PROC_CLIENT_CLOSE = 11,
        ADMIN_PROC_SERVER_GET_CLIENT_LIMITS = 12,
        ADMIN_PROC_SERVER_SET_CLIENT_LIMITS = 13,
        ADMIN_PROC_CONNECT_GET_LOGGING_OUTPUTS = 14,
        ADMIN_PROC_CONNECT_GET_LOGGING_FILTERS = 15,
        ADMIN_PROC_CONNECT_SET_LOGGING_OUTPUTS = 16,
        ADMIN_PROC_CONNECT_SET_LOGGING_FILTERS = 17,
};
typedef enum admin_procedure admin_procedure;

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_admin_nonnull_string (XDR *, admin_nonnull_string*);
extern  bool_t xdr_admin_string (XDR *, admin_string*);
extern  bool_t xdr_admin_typed_param_value (XDR *, admin_typed_param_value*);
extern  bool_t xdr_admin_typed_param (XDR *, admin_typed_param*);
extern  bool_t xdr_admin_nonnull_server (XDR *, admin_nonnull_server*);
extern  bool_t xdr_admin_nonnull_client (XDR *, admin_nonnull_client*);
extern  bool_t xdr_admin_connect_open_args (XDR *, admin_connect_open_args*);
extern  bool_t xdr_admin_connect_get_lib_version_ret (XDR *, admin_connect_get_lib_version_ret*);
extern  bool_t xdr_admin_connect_list_servers_args (XDR *, admin_connect_list_servers_args*);
extern  bool_t xdr_admin_connect_list_servers_ret (XDR *, admin_connect_list_servers_ret*);
extern  bool_t xdr_admin_connect_lookup_server_args (XDR *, admin_connect_lookup_server_args*);
extern  bool_t xdr_admin_connect_lookup_server_ret (XDR *, admin_connect_lookup_server_ret*);
extern  bool_t xdr_admin_server_get_threadpool_parameters_args (XDR *, admin_server_get_threadpool_parameters_args*);
extern  bool_t xdr_admin_server_get_threadpool_parameters_ret (XDR *, admin_server_get_threadpool_parameters_ret*);
extern  bool_t xdr_admin_server_set_threadpool_parameters_args (XDR *, admin_server_set_threadpool_parameters_args*);
extern  bool_t xdr_admin_server_list_clients_args (XDR *, admin_server_list_clients_args*);
extern  bool_t xdr_admin_server_list_clients_ret (XDR *, admin_server_list_clients_ret*);
extern  bool_t xdr_admin_server_lookup_client_args (XDR *, admin_server_lookup_client_args*);
extern  bool_t xdr_admin_server_lookup_client_ret (XDR *, admin_server_lookup_client_ret*);
extern  bool_t xdr_admin_client_get_info_args (XDR *, admin_client_get_info_args*);
extern  bool_t xdr_admin_client_get_info_ret (XDR *, admin_client_get_info_ret*);
extern  bool_t xdr_admin_client_close_args (XDR *, admin_client_close_args*);
extern  bool_t xdr_admin_server_get_client_limits_args (XDR *, admin_server_get_client_limits_args*);
extern  bool_t xdr_admin_server_get_client_limits_ret (XDR *, admin_server_get_client_limits_ret*);
extern  bool_t xdr_admin_server_set_client_limits_args (XDR *, admin_server_set_client_limits_args*);
extern  bool_t xdr_admin_connect_get_logging_outputs_args (XDR *, admin_connect_get_logging_outputs_args*);
extern  bool_t xdr_admin_connect_get_logging_outputs_ret (XDR *, admin_connect_get_logging_outputs_ret*);
extern  bool_t xdr_admin_connect_get_logging_filters_args (XDR *, admin_connect_get_logging_filters_args*);
extern  bool_t xdr_admin_connect_get_logging_filters_ret (XDR *, admin_connect_get_logging_filters_ret*);
extern  bool_t xdr_admin_connect_set_logging_outputs_args (XDR *, admin_connect_set_logging_outputs_args*);
extern  bool_t xdr_admin_connect_set_logging_filters_args (XDR *, admin_connect_set_logging_filters_args*);
extern  bool_t xdr_admin_procedure (XDR *, admin_procedure*);

#else /* K&R C */
extern bool_t xdr_admin_nonnull_string ();
extern bool_t xdr_admin_string ();
extern bool_t xdr_admin_typed_param_value ();
extern bool_t xdr_admin_typed_param ();
extern bool_t xdr_admin_nonnull_server ();
extern bool_t xdr_admin_nonnull_client ();
extern bool_t xdr_admin_connect_open_args ();
extern bool_t xdr_admin_connect_get_lib_version_ret ();
extern bool_t xdr_admin_connect_list_servers_args ();
extern bool_t xdr_admin_connect_list_servers_ret ();
extern bool_t xdr_admin_connect_lookup_server_args ();
extern bool_t xdr_admin_connect_lookup_server_ret ();
extern bool_t xdr_admin_server_get_threadpool_parameters_args ();
extern bool_t xdr_admin_server_get_threadpool_parameters_ret ();
extern bool_t xdr_admin_server_set_threadpool_parameters_args ();
extern bool_t xdr_admin_server_list_clients_args ();
extern bool_t xdr_admin_server_list_clients_ret ();
extern bool_t xdr_admin_server_lookup_client_args ();
extern bool_t xdr_admin_server_lookup_client_ret ();
extern bool_t xdr_admin_client_get_info_args ();
extern bool_t xdr_admin_client_get_info_ret ();
extern bool_t xdr_admin_client_close_args ();
extern bool_t xdr_admin_server_get_client_limits_args ();
extern bool_t xdr_admin_server_get_client_limits_ret ();
extern bool_t xdr_admin_server_set_client_limits_args ();
extern bool_t xdr_admin_connect_get_logging_outputs_args ();
extern bool_t xdr_admin_connect_get_logging_outputs_ret ();
extern bool_t xdr_admin_connect_get_logging_filters_args ();
extern bool_t xdr_admin_connect_get_logging_filters_ret ();
extern bool_t xdr_admin_connect_set_logging_outputs_args ();
extern bool_t xdr_admin_connect_set_logging_filters_args ();
extern bool_t xdr_admin_procedure ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ADMIN_PROTOCOL_H_RPCGEN */

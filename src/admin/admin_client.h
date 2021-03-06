/* Automatically generated from ./admin/admin_protocol.x by gendispatch.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */

static int
remoteAdminClientClose(virAdmClientPtr clnt, unsigned int flags)
{
    int rv = -1;
    remoteAdminPrivPtr priv = clnt->srv->conn->privateData;
    admin_client_close_args args;

    virObjectLock(priv);

    make_nonnull_client(&args.clnt, clnt);
    args.flags = flags;

    if (call(clnt->srv->conn, 0, ADMIN_PROC_CLIENT_CLOSE,
             (xdrproc_t)xdr_admin_client_close_args, (char *)&args,
             (xdrproc_t)xdr_void, (char *)NULL) == -1) {
        goto done;
    }

    rv = 0;

done:
    virObjectUnlock(priv);
    return rv;
}

static int
remoteAdminConnectGetLibVersion(virAdmConnectPtr conn, unsigned long long *libVer)
{
    int rv = -1;
    remoteAdminPrivPtr priv = conn->privateData;
    admin_connect_get_lib_version_ret ret;

    virObjectLock(priv);

    memset(&ret, 0, sizeof(ret));

    if (call(conn, 0, ADMIN_PROC_CONNECT_GET_LIB_VERSION,
             (xdrproc_t)xdr_void, (char *)NULL,
             (xdrproc_t)xdr_admin_connect_get_lib_version_ret, (char *)&ret) == -1) {
        goto done;
    }

    *libVer = ret.libVer;
    rv = 0;

done:
    virObjectUnlock(priv);
    return rv;
}

static int
remoteAdminConnectListServers(virAdmConnectPtr conn, virAdmServerPtr **result, unsigned int flags)
{
    int rv = -1;
    remoteAdminPrivPtr priv = conn->privateData;
    admin_connect_list_servers_args args;
    admin_connect_list_servers_ret ret;
    virAdmServerPtr *tmp_results = NULL;
    size_t i;

    virObjectLock(priv);

    args.flags = flags;
    args.need_results = !!result;

    memset(&ret, 0, sizeof(ret));

    if (call(conn, 0, ADMIN_PROC_CONNECT_LIST_SERVERS,
             (xdrproc_t)xdr_admin_connect_list_servers_args, (char *)&args,
             (xdrproc_t)xdr_admin_connect_list_servers_ret, (char *)&ret) == -1) {
        goto done;
    }

    if (ret.servers.servers_len > ADMIN_SERVER_LIST_MAX) {
        virReportError(VIR_ERR_RPC,
                       _("too many remote servers: %d > %d,"
                         "in parameter 'servers' for 'virConnectListServers'"),
                       ret.servers.servers_len, ADMIN_SERVER_LIST_MAX);
        goto cleanup;
    }

    if (result) {
        if (VIR_ALLOC_N(tmp_results, ret.servers.servers_len + 1) < 0)
            goto cleanup;

        for (i = 0; i < ret.servers.servers_len; i++) {
            tmp_results[i] = get_nonnull_server(conn, ret.servers.servers_val[i]);
            if (!tmp_results[i])
                goto cleanup;
        }
        *result = tmp_results;
        tmp_results = NULL;
    }

    rv = ret.ret;

cleanup:
    if (tmp_results) {
        for (i = 0; i < ret.servers.servers_len; i++)
            virObjectUnref(tmp_results[i]);
        VIR_FREE(tmp_results);
    }

    xdr_free((xdrproc_t)xdr_admin_connect_list_servers_ret, (char *)&ret);

done:
    virObjectUnlock(priv);
    return rv;
}

static virAdmServerPtr
remoteAdminConnectLookupServer(virAdmConnectPtr conn, const char *name, unsigned int flags)
{
    virAdmServerPtr rv = NULL;
    remoteAdminPrivPtr priv = conn->privateData;
    admin_connect_lookup_server_args args;
    admin_connect_lookup_server_ret ret;

    virObjectLock(priv);

    args.name = (char *)name;
    args.flags = flags;

    memset(&ret, 0, sizeof(ret));

    if (call(conn, 0, ADMIN_PROC_CONNECT_LOOKUP_SERVER,
             (xdrproc_t)xdr_admin_connect_lookup_server_args, (char *)&args,
             (xdrproc_t)xdr_admin_connect_lookup_server_ret, (char *)&ret) == -1) {
        goto done;
    }

    rv = get_nonnull_server(conn, ret.srv);
    xdr_free((xdrproc_t)xdr_admin_connect_lookup_server_ret, (char *)&ret);

done:
    virObjectUnlock(priv);
    return rv;
}

static int
remoteAdminConnectSetLoggingFilters(virAdmConnectPtr conn, const char *filters, unsigned int flags)
{
    int rv = -1;
    remoteAdminPrivPtr priv = conn->privateData;
    admin_connect_set_logging_filters_args args;

    virObjectLock(priv);

    args.filters = filters ? (char **)&filters : NULL;
    args.flags = flags;

    if (call(conn, 0, ADMIN_PROC_CONNECT_SET_LOGGING_FILTERS,
             (xdrproc_t)xdr_admin_connect_set_logging_filters_args, (char *)&args,
             (xdrproc_t)xdr_void, (char *)NULL) == -1) {
        goto done;
    }

    rv = 0;

done:
    virObjectUnlock(priv);
    return rv;
}

static int
remoteAdminConnectSetLoggingOutputs(virAdmConnectPtr conn, const char *outputs, unsigned int flags)
{
    int rv = -1;
    remoteAdminPrivPtr priv = conn->privateData;
    admin_connect_set_logging_outputs_args args;

    virObjectLock(priv);

    args.outputs = outputs ? (char **)&outputs : NULL;
    args.flags = flags;

    if (call(conn, 0, ADMIN_PROC_CONNECT_SET_LOGGING_OUTPUTS,
             (xdrproc_t)xdr_admin_connect_set_logging_outputs_args, (char *)&args,
             (xdrproc_t)xdr_void, (char *)NULL) == -1) {
        goto done;
    }

    rv = 0;

done:
    virObjectUnlock(priv);
    return rv;
}

static int
remoteAdminServerListClients(virAdmServerPtr srv, virAdmClientPtr **result, unsigned int flags)
{
    int rv = -1;
    remoteAdminPrivPtr priv = srv->conn->privateData;
    admin_server_list_clients_args args;
    admin_server_list_clients_ret ret;
    virAdmClientPtr *tmp_results = NULL;
    size_t i;

    virObjectLock(priv);

    make_nonnull_server(&args.srv, srv);
    args.flags = flags;
    args.need_results = !!result;

    memset(&ret, 0, sizeof(ret));

    if (call(srv->conn, 0, ADMIN_PROC_SERVER_LIST_CLIENTS,
             (xdrproc_t)xdr_admin_server_list_clients_args, (char *)&args,
             (xdrproc_t)xdr_admin_server_list_clients_ret, (char *)&ret) == -1) {
        goto done;
    }

    if (ret.clients.clients_len > ADMIN_CLIENT_LIST_MAX) {
        virReportError(VIR_ERR_RPC,
                       _("too many remote clients: %d > %d,"
                         "in parameter 'clients' for 'virServerListClients'"),
                       ret.clients.clients_len, ADMIN_CLIENT_LIST_MAX);
        goto cleanup;
    }

    if (result) {
        if (VIR_ALLOC_N(tmp_results, ret.clients.clients_len + 1) < 0)
            goto cleanup;

        for (i = 0; i < ret.clients.clients_len; i++) {
            tmp_results[i] = get_nonnull_client(srv, ret.clients.clients_val[i]);
            if (!tmp_results[i])
                goto cleanup;
        }
        *result = tmp_results;
        tmp_results = NULL;
    }

    rv = ret.ret;

cleanup:
    if (tmp_results) {
        for (i = 0; i < ret.clients.clients_len; i++)
            virObjectUnref(tmp_results[i]);
        VIR_FREE(tmp_results);
    }

    xdr_free((xdrproc_t)xdr_admin_server_list_clients_ret, (char *)&ret);

done:
    virObjectUnlock(priv);
    return rv;
}

static virAdmClientPtr
remoteAdminServerLookupClient(virAdmServerPtr srv, unsigned long long id, unsigned int flags)
{
    virAdmClientPtr rv = NULL;
    remoteAdminPrivPtr priv = srv->conn->privateData;
    admin_server_lookup_client_args args;
    admin_server_lookup_client_ret ret;

    virObjectLock(priv);

    make_nonnull_server(&args.srv, srv);
    args.id = id;
    args.flags = flags;

    memset(&ret, 0, sizeof(ret));

    if (call(srv->conn, 0, ADMIN_PROC_SERVER_LOOKUP_CLIENT,
             (xdrproc_t)xdr_admin_server_lookup_client_args, (char *)&args,
             (xdrproc_t)xdr_admin_server_lookup_client_ret, (char *)&ret) == -1) {
        goto done;
    }

    rv = get_nonnull_client(srv, ret.clnt);
    xdr_free((xdrproc_t)xdr_admin_server_lookup_client_ret, (char *)&ret);

done:
    virObjectUnlock(priv);
    return rv;
}

/*
 * applets.h - a listing of all busybox applets.
 *
 * If you write a new applet, you need to add an entry to this list to make
 * busybox aware of it.
 *
 * It is CRUCIAL that this listing be kept in ascii order, otherwise the binary
 * search lookup contributed by Gaute B Strokkenes stops working. If you value
 * your kneecaps, you'll be sure to *make sure* that any changes made to this
 * file result in the listing remaining in ascii order. You have been warned.
 */

#undef APPLET
#undef APPLET_ODDNAME
#undef APPLET_NOUSAGE


#if defined(PROTOTYPES)
# define APPLET(a,b,c,d) extern int b(int argc, char **argv);
# define APPLET_NOUSAGE(a,b,c,d) extern int b(int argc, char **argv);
# define APPLET_ODDNAME(a,b,c,d,e) extern int b(int argc, char **argv);
#elif defined(MAKE_USAGE)
# ifdef CONFIG_FEATURE_VERBOSE_USAGE
#  define APPLET(a,b,c,d) a##_trivial_usage "\n\n" a##_full_usage "\0"
#  define APPLET_NOUSAGE(a,b,c,d) "\b\0"
#  define APPLET_ODDNAME(a,b,c,d,e) e##_trivial_usage "\n\n" e##_full_usage "\0"
# else
#  define APPLET(a,b,c,d) a##_trivial_usage "\0"
#  define APPLET_NOUSAGE(a,b,c,d) "\b\0"
#  define APPLET_ODDNAME(a,b,c,d,e) e##_trivial_usage "\0"
# endif
#elif defined(MAKE_LINKS)
# define APPLET(a,b,c,d) LINK c a
# define APPLET_NOUSAGE(a,b,c,d) LINK c a
# define APPLET_ODDNAME(a,b,c,d,e) LINK c a
#else
  const struct BB_applet applets[] = {
# define APPLET(a,b,c,d) {#a,b,c,d},
# define APPLET_NOUSAGE(a,b,c,d) {#a,b,c,d},
# define APPLET_ODDNAME(a,b,c,d,e) {#a,b,c,d},
#endif

#ifdef CONFIG_INSTALL_NO_USR
# define _BB_DIR_USR_BIN _BB_DIR_BIN
# define _BB_DIR_USR_SBIN _BB_DIR_SBIN
#endif


USE_TEST(APPLET_NOUSAGE([, test_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TEST(APPLET_NOUSAGE([[, test_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_ADDGROUP(APPLET(addgroup, addgroup_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_ADDUSER(APPLET(adduser, adduser_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_ADJTIMEX(APPLET(adjtimex, adjtimex_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_AR(APPLET(ar, ar_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_ARPING(APPLET(arping, arping_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_ASH(APPLET_NOUSAGE(ash, ash_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_AWK(APPLET(awk, awk_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_BASENAME(APPLET(basename, basename_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_BBCONFIG(APPLET(bbconfig, bbconfig_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_BUNZIP2(APPLET(bunzip2, bunzip2_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
/* Always enabled. */
APPLET_NOUSAGE(busybox, busybox_main, _BB_DIR_BIN, _BB_SUID_MAYBE)
USE_BUNZIP2(APPLET(bzcat, bunzip2_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_CAL(APPLET(cal, cal_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_CAT(APPLET(cat, cat_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CHATTR(APPLET(chattr, chattr_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CHGRP(APPLET(chgrp, chgrp_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CHMOD(APPLET(chmod, chmod_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CHOWN(APPLET(chown, chown_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CHROOT(APPLET(chroot, chroot_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_CHVT(APPLET(chvt, chvt_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_CKSUM(APPLET(cksum, cksum_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_CLEAR(APPLET(clear, clear_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_CMP(APPLET(cmp, cmp_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_COMM(APPLET(comm, comm_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_CP(APPLET(cp, cp_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CPIO(APPLET(cpio, cpio_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_CROND(APPLET(crond, crond_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_CRONTAB(APPLET(crontab, crontab_main, _BB_DIR_USR_BIN, _BB_SUID_ALWAYS))
USE_CUT(APPLET(cut, cut_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DATE(APPLET(date, date_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DC(APPLET(dc, dc_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DD(APPLET(dd, dd_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DEALLOCVT(APPLET(deallocvt, deallocvt_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DELGROUP(APPLET(delgroup, deluser_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DELUSER(APPLET(deluser, deluser_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DEVFSD(APPLET(devfsd, devfsd_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_DF(APPLET(df, df_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DIFF(APPLET(diff, diff_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DIRNAME(APPLET(dirname, dirname_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DMESG(APPLET(dmesg, dmesg_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DNSD(APPLET(dnsd, dnsd_main, _BB_DIR_USR_SBIN, _BB_SUID_ALWAYS))
USE_DOS2UNIX(APPLET(dos2unix, dos2unix_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DPKG(APPLET(dpkg, dpkg_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DPKG_DEB(APPLET_ODDNAME(dpkg-deb, dpkg_deb_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER, dpkg_deb))
USE_DU(APPLET(du, du_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_DUMPKMAP(APPLET(dumpkmap, dumpkmap_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_DUMPLEASES(APPLET(dumpleases, dumpleases_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_E2FSCK(APPLET(e2fsck, e2fsck_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_E2LABEL(APPLET_NOUSAGE(e2label, tune2fs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_ECHO(APPLET(echo, echo_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FEATURE_GREP_EGREP_ALIAS(APPLET_NOUSAGE(egrep, grep_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_EJECT(APPLET(eject, eject_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_ENV(APPLET(env, env_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_ETHER_WAKE(APPLET_ODDNAME(ether-wake, etherwake_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER, ether_wake))
USE_EXPR(APPLET(expr, expr_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FAKEIDENTD(APPLET(fakeidentd, fakeidentd_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_FALSE(APPLET(false, false_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FBSET(APPLET(fbset, fbset_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_FDFLUSH(APPLET(fdflush, freeramdisk_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FDFORMAT(APPLET(fdformat, fdformat_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FDISK(APPLET(fdisk, fdisk_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_FEATURE_GREP_FGREP_ALIAS(APPLET_NOUSAGE(fgrep, grep_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FIND(APPLET(find, find_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FINDFS(APPLET_NOUSAGE(findfs, tune2fs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_FOLD(APPLET(fold, fold_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FREE(APPLET(free, free_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FREERAMDISK(APPLET(freeramdisk, freeramdisk_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_FSCK(APPLET(fsck, fsck_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_E2FSCK(APPLET_NOUSAGE(fsck.ext2, e2fsck_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_E2FSCK(APPLET_NOUSAGE(fsck.ext3, e2fsck_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_FSCK_MINIX(APPLET_ODDNAME(fsck.minix, fsck_minix_main, _BB_DIR_SBIN, _BB_SUID_NEVER, fsck_minix))
USE_FTPGET(APPLET(ftpget, ftpgetput_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FTPPUT(APPLET(ftpput, ftpgetput_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FUSER(APPLET(fuser, fuser_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_GETOPT(APPLET(getopt, getopt_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_GETTY(APPLET(getty, getty_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_GREP(APPLET(grep, grep_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_GUNZIP(APPLET(gunzip, gunzip_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_GZIP(APPLET(gzip, gzip_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_HALT(APPLET(halt, halt_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_HDPARM(APPLET(hdparm, hdparm_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_HEAD(APPLET(head, head_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_HEXDUMP(APPLET(hexdump, hexdump_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_HOSTID(APPLET(hostid, hostid_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_HOSTNAME(APPLET(hostname, hostname_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_HTTPD(APPLET(httpd, httpd_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_HUSH(APPLET_NOUSAGE(hush, hush_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_HWCLOCK(APPLET(hwclock, hwclock_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_ID(APPLET(id, id_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_IFCONFIG(APPLET(ifconfig, ifconfig_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_IFUPDOWN(APPLET(ifdown, ifupdown_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_IFUPDOWN(APPLET(ifup, ifupdown_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_INETD(APPLET(inetd, inetd_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_INIT(APPLET(init, init_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_INSMOD(APPLET(insmod, insmod_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_INSTALL(APPLET(install, install_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_IP(APPLET(ip, ip_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_IPADDR(APPLET(ipaddr, ipaddr_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_IPCALC(APPLET(ipcalc, ipcalc_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_IPCRM(APPLET(ipcrm, ipcrm_main, _BB_DIR_USR_BIN, _BB_SUID_ALWAYS))
USE_IPCS(APPLET(ipcs, ipcs_main, _BB_DIR_USR_BIN, _BB_SUID_ALWAYS))
USE_IPLINK(APPLET(iplink, iplink_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_IPROUTE(APPLET(iproute, iproute_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_IPTUNNEL(APPLET(iptunnel, iptunnel_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_KILL(APPLET(kill, kill_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_KILLALL(APPLET(killall, kill_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_KLOGD(APPLET(klogd, klogd_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_LASH(APPLET(lash, lash_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_LAST(APPLET(last, last_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_LENGTH(APPLET(length, length_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_LESS(APPLET(less, less_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_SETARCH(APPLET_NOUSAGE(linux32, setarch_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_SETARCH(APPLET_NOUSAGE(linux64, setarch_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FEATURE_INITRD(APPLET_NOUSAGE(linuxrc, init_main, _BB_DIR_ROOT, _BB_SUID_NEVER))
USE_LN(APPLET(ln, ln_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_LOADFONT(APPLET(loadfont, loadfont_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_LOADKMAP(APPLET(loadkmap, loadkmap_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_LOGGER(APPLET(logger, logger_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_LOGIN(APPLET(login, login_main, _BB_DIR_BIN, _BB_SUID_ALWAYS))
USE_LOGNAME(APPLET(logname, logname_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_LOGREAD(APPLET(logread, logread_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_LOSETUP(APPLET(losetup, losetup_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_LS(APPLET(ls, ls_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_LSATTR(APPLET(lsattr, lsattr_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_LSMOD(APPLET(lsmod, lsmod_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_UNLZMA(APPLET(lzmacat, unlzma_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_MAKEDEVS(APPLET(makedevs, makedevs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MD5SUM(APPLET(md5sum, md5sum_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_MDEV(APPLET(mdev, mdev_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MESG(APPLET(mesg, mesg_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_MKDIR(APPLET(mkdir, mkdir_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MKE2FS(APPLET(mke2fs, mke2fs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MKFIFO(APPLET(mkfifo, mkfifo_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_MKE2FS(APPLET_NOUSAGE(mkfs.ext2, mke2fs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MKE2FS(APPLET_NOUSAGE(mkfs.ext3, mke2fs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MKFS_MINIX(APPLET_ODDNAME(mkfs.minix, mkfs_minix_main, _BB_DIR_SBIN, _BB_SUID_NEVER, mkfs_minix))
USE_MKNOD(APPLET(mknod, mknod_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MKSWAP(APPLET(mkswap, mkswap_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MKTEMP(APPLET(mktemp, mktemp_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MODPROBE(APPLET(modprobe, modprobe_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_MORE(APPLET(more, more_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MOUNT(APPLET(mount, mount_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MOUNTPOINT(APPLET(mountpoint, mountpoint_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MSH(APPLET_NOUSAGE(msh, msh_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MT(APPLET(mt, mt_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_MV(APPLET(mv, mv_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_NAMEIF(APPLET(nameif, nameif_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_NC(APPLET(nc, nc_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_NETSTAT(APPLET(netstat, netstat_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_NICE(APPLET(nice, nice_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_NOHUP(APPLET(nohup, nohup_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_NSLOOKUP(APPLET(nslookup, nslookup_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_OD(APPLET(od, od_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_OPENVT(APPLET(openvt, openvt_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_PASSWD(APPLET(passwd, passwd_main, _BB_DIR_USR_BIN, _BB_SUID_ALWAYS))
USE_PATCH(APPLET(patch, patch_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_PIDOF(APPLET(pidof, pidof_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_PING(APPLET(ping, ping_main, _BB_DIR_BIN, _BB_SUID_MAYBE))
USE_PING6(APPLET(ping6, ping6_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_PIPE_PROGRESS(APPLET_NOUSAGE(pipe_progress, pipe_progress_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_PIVOT_ROOT(APPLET(pivot_root, pivot_root_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_HALT(APPLET(poweroff, halt_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_PRINTENV(APPLET(printenv, printenv_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_PRINTF(APPLET(printf, printf_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_PS(APPLET(ps, ps_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_PWD(APPLET(pwd, pwd_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_RDATE(APPLET(rdate, rdate_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_READLINK(APPLET(readlink, readlink_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_READPROFILE(APPLET(readprofile, readprofile_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_REALPATH(APPLET(realpath, realpath_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_HALT(APPLET(reboot, halt_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_RENICE(APPLET(renice, renice_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_RESET(APPLET(reset, reset_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_RM(APPLET(rm, rm_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_RMDIR(APPLET(rmdir, rmdir_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_RMMOD(APPLET(rmmod, rmmod_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_ROUTE(APPLET(route, route_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_RPM(APPLET(rpm, rpm_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_RPM2CPIO(APPLET(rpm2cpio, rpm2cpio_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_RUN_PARTS(APPLET_ODDNAME(run-parts, run_parts_main, _BB_DIR_BIN, _BB_SUID_NEVER, run_parts))
USE_RUNLEVEL(APPLET(runlevel, runlevel_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_RX(APPLET(rx, rx_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_SED(APPLET(sed, sed_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_SEQ(APPLET(seq, seq_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_SETARCH(APPLET(setarch, setarch_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_SETCONSOLE(APPLET(setconsole, setconsole_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_SETKEYCODES(APPLET(setkeycodes, setkeycodes_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_SETLOGCONS(APPLET(setlogcons, setlogcons_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_SETSID(APPLET(setsid, setsid_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_FEATURE_SH_IS_ASH(APPLET_NOUSAGE(sh, ash_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FEATURE_SH_IS_HUSH(APPLET_NOUSAGE(sh, hush_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FEATURE_SH_IS_LASH(APPLET_NOUSAGE(sh, lash_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_FEATURE_SH_IS_MSH(APPLET_NOUSAGE(sh, msh_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_SHA1SUM(APPLET(sha1sum, sha1sum_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_SLEEP(APPLET(sleep, sleep_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_SORT(APPLET(sort, sort_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_START_STOP_DAEMON(APPLET_ODDNAME(start-stop-daemon, start_stop_daemon_main, _BB_DIR_SBIN, _BB_SUID_NEVER, start_stop_daemon))
USE_STAT(APPLET(stat, stat_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_STRINGS(APPLET(strings, strings_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_STTY(APPLET(stty, stty_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_SU(APPLET(su, su_main, _BB_DIR_BIN, _BB_SUID_ALWAYS))
USE_SULOGIN(APPLET(sulogin, sulogin_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_SUM(APPLET(sum, sum_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_SWAPONOFF(APPLET(swapoff, swap_on_off_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_SWAPONOFF(APPLET(swapon, swap_on_off_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_SWITCH_ROOT(APPLET(switch_root, switch_root_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_SYNC(APPLET(sync, sync_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_BB_SYSCTL(APPLET(sysctl, sysctl_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_SYSLOGD(APPLET(syslogd, syslogd_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_TAIL(APPLET(tail, tail_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TAR(APPLET(tar, tar_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_TEE(APPLET(tee, tee_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TELNET(APPLET(telnet, telnet_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TELNETD(APPLET(telnetd, telnetd_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_TEST(APPLET(test, test_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TFTP(APPLET(tftp, tftp_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TIME(APPLET(time, time_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TOP(APPLET(top, top_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TOUCH(APPLET(touch, touch_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_TR(APPLET(tr, tr_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TRACEROUTE(APPLET(traceroute, traceroute_main, _BB_DIR_USR_BIN, _BB_SUID_MAYBE))
USE_TRUE(APPLET(true, true_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_TTY(APPLET(tty, tty_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_TUNE2FS(APPLET(tune2fs, tune2fs_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_UDHCPC(APPLET(udhcpc, udhcpc_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_UDHCPD(APPLET(udhcpd, udhcpd_main, _BB_DIR_USR_SBIN, _BB_SUID_NEVER))
USE_UMOUNT(APPLET(umount, umount_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_UNAME(APPLET(uname, uname_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_UNCOMPRESS(APPLET(uncompress, uncompress_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_UNIQ(APPLET(uniq, uniq_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_UNIX2DOS(APPLET(unix2dos, dos2unix_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_UNLZMA(APPLET(unlzma, unlzma_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_UNZIP(APPLET(unzip, unzip_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_UPTIME(APPLET(uptime, uptime_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_USLEEP(APPLET(usleep, usleep_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_UUDECODE(APPLET(uudecode, uudecode_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_UUENCODE(APPLET(uuencode, uuencode_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_VCONFIG(APPLET(vconfig, vconfig_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_VI(APPLET(vi, vi_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_VLOCK(APPLET(vlock, vlock_main, _BB_DIR_USR_BIN, _BB_SUID_ALWAYS))
USE_WATCH(APPLET(watch, watch_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_WATCHDOG(APPLET(watchdog, watchdog_main, _BB_DIR_SBIN, _BB_SUID_NEVER))
USE_WC(APPLET(wc, wc_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_WGET(APPLET(wget, wget_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_WHICH(APPLET(which, which_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_WHO(APPLET(who, who_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_WHOAMI(APPLET(whoami, whoami_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_XARGS(APPLET(xargs, xargs_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_YES(APPLET(yes, yes_main, _BB_DIR_USR_BIN, _BB_SUID_NEVER))
USE_GUNZIP(APPLET(zcat, gunzip_main, _BB_DIR_BIN, _BB_SUID_NEVER))
USE_ZCIP(APPLET(zcip, zcip_main, _BB_DIR_SBIN, _BB_SUID_NEVER))

#if !defined(PROTOTYPES) && !defined(MAKE_USAGE)
	{ 0,NULL,0,0 }
};

#endif

#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7609cf7, "module_layout" },
	{ 0x6505ce85, "unregister_filesystem" },
	{ 0xc5850110, "printk" },
	{ 0x1834526a, "register_filesystem" },
	{ 0x7e526bfa, "__x86_indirect_thunk_r10" },
	{ 0x3eb54c98, "pv_ops" },
	{ 0xdbf17652, "_raw_spin_lock" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0x8637149b, "mount_nodev" },
	{ 0xa9cd761c, "kill_anon_super" },
	{ 0xda26cee3, "d_make_root" },
	{ 0x2a16b549, "simple_unlink" },
	{ 0xf100c3e8, "simple_rmdir" },
	{ 0xe914e41e, "strcpy" },
	{ 0xf8193041, "d_add" },
	{ 0x5199ad9f, "inode_init_owner" },
	{ 0x7435bd8c, "new_inode" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x56470118, "__warn_printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0336BEF795C6E48DE7CD2B9");

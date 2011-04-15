env = Environment(CCFLAGS = ['-W', '-Wall', '-I./src'])

tst = env.Clone()
tst.AppendUnique(CCFLAGS = ['-I./tst'])

dbg = env.Clone()
dbg.AppendUnique(CCFLAGS = ['-g', '-DDEBUG'])

opt = env.Clone()
opt.AppendUnique(CCFLAGS = ['-O3'])

test = SConscript('tst/SConscript', exports = {'env': tst}, variant_dir = 'test', duplicate = 0)
debug = SConscript('src/SConscript', exports = {'env': dbg}, variant_dir = 'debug', duplicate = 0)
release = SConscript('src/SConscript', exports = {'env': opt}, variant_dir = 'release', duplicate = 0)

Default('debug')
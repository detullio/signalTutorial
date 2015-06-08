#import Glob

env = Environment(LIBS = ['stdc++', 'pthread', 'boost_system', 'boost_thread', 'boost_log'],
                  CXXFLAGS = (['-DBOOST_LOG_DYN_LINK', '-ggdb3', '-Wall', '-Wextra', '-Wpedantic', '-Weffc++', '-std=c++11']),
                  LINKFLAGS = (['-ggdb3']))

headerFiles = Glob('*.h')

sourceFiles = Glob('*.cpp')

env.Program(target =  'signalThread',  source = sourceFiles)

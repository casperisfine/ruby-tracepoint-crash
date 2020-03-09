require "bundler/gem_tasks"
require "rake/testtask"


GEMSPEC = eval(File.read('ruby-tracepoint-crash.gemspec'))
require 'rake/extensiontask'
Rake::ExtensionTask.new('tracepoint_crash', GEMSPEC) do |ext|
  ext.ext_dir = 'ext/tracepoint_crash'
end
task :build => :compile

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
  t.libs << "lib"
  t.test_files = FileList["test/**/*_test.rb"]
end
task :test => :compile

task :default => :test

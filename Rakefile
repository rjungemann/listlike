CC = 'clang -O3 -Wall -Wpedantic -pedantic-errors -Wextra -I src'

namespace :test do
  desc ''
  task :clean do
    sh 'rm -f listlike-test'
  end

  desc ''
  task :build do
    sh "#{CC} src/listlike-test.c -o listlike-test"
    sh 'chmod 755 listlike-test'
  end

  desc ''
  task :run do
    sh './listlike-test'
  end
end

task :default do
  Rake::Task['test:clean'].invoke
  Rake::Task['test:build'].invoke
  Rake::Task['test:run'].invoke
end

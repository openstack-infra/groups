Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"
  config.ssh.shell = "bash -c 'BASH_ENV=/etc/profile exec bash'"
  config.vm.provider 'virtualbox' do |vb|
    vb.memory = 2048
    vb.cpus = 2
  end
  config.vm.hostname = "groups"
  config.vm.network "forwarded_port", guest: 80, host: 60080
  config.vm.provision "shell", inline: $script
end

$script = <<SCRIPT
export DEBIAN_FRONTEND=noninteractive
apt-get update && apt-get upgrade -y
apt-get install -y ruby-bundler lamp-server^
rm /var/www/html/index.html
cd /vagrant
[ -d /vagrant/publish ] && rm -r /vagrant/publish
/vagrant/scripts/bootstrap.sh
/vagrant/scripts/dev-build.sh
rsync -avz --delete-before /vagrant/publish/ /var/www/html/
chown -R www-data:www-data /var/www/html
sed -i 's/max_execution_time = .*/max_execution_time = 120/' /etc/php5/apache2/php.ini
service apache2 restart
mysql <<EOF
DROP DATABASE IF EXISTS groups;
CREATE DATABASE groups;
GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, ALTER
  ON groups.*
  TO 'groups'@'localhost' IDENTIFIED BY 'password';
EOF
SCRIPT

Pod::Spec.new do |s|
s.name                  = 'SINAdFramework'
s.version               = '1.0'
s.summary               = '搜狐资讯广告sdk'
s.homepage              = ''
s.license               = { :type => 'MIT'}
s.author                = { 'xxx' => 'xxx@163.com' }
s.source                = { :git => 'git@gitlab.adrd.sohuno.com:iOSSpecs/SINAdSpec.git', :tag => "{s.version}" }
s.platform              = :ios, '7.0'
s.source_files          = ''
s.requires_arc          = true
end
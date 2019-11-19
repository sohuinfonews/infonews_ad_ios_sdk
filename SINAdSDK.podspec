Pod::Spec.new do |s|
s.name                  = 'SINAdSDK'
s.version               = '0.1.1'
s.summary               = '搜狐资讯广告sdk'
s.homepage              = 'https://github.com/sohuinfonews/infonews_ad_ios_sdk'
s.description           = 'DESC infonews_ad_ios_sdk pod.DESC'
s.license               = { :type => 'MIT', :file => 'LICENSE' }
s.author                = { 'xiaoxiao' => 'shawnxiao@sohu-inc.com', 'jialei' => 'leijia200990@sohu-inc.com' }
s.source                = { :git => 'https://github.com/sohuinfonews/infonews_ad_ios_sdk.git', :tag => s.version.to_s }
s.platform              = :ios, '9.0'
s.resource              = 'SINAdFramework/SINAdSDK.bundle'
s.vendored_frameworks   = 'SINAdFramework/SINSSPADFramework.framework'
end
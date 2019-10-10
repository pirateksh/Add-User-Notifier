from channels.routing import ProtocolTypeRouter, URLRouter
from django.urls import path

from notifier.consumers import EchoConsumer
from notifier.consumers import TickTockConsumer

# ProtocolTypeRouter is used to identify what protocol is being used.
"""
application = ProtocolTypeRouter({
	"websocket": URLRouter([
		path("ws/", EchoConsumer),
	]),
})
"""

# ProtocolTypeRouter is used to identify what protocol is being used.
application = ProtocolTypeRouter({
	"websocket": URLRouter([
		# Path is routed to TickTockConsumer
		path("ws/", TickTockConsumer),
	]),
})
from channels.routing import ProtocolTypeRouter, URLRouter
from django.urls import path

from notifier.consumers import EchoConsumer, TickTockConsumer, NoseyConsumer


# ProtocolTypeRouter is used to identify what protocol is being used.

"""
application = ProtocolTypeRouter({
	"websocket": URLRouter([
		path("ws/", EchoConsumer),
	]),
})
"""


"""
application = ProtocolTypeRouter({
	"websocket": URLRouter([
		# Path is routed to TickTockConsumer
		path("ws/", TickTockConsumer),
	]),
})
"""


application = ProtocolTypeRouter({
	"websocket": URLRouter([
		# Path is routed to NoseyConsumer
		# Changing path to notifications/ instead of ws/
		path("notifications/", NoseyConsumer),
	]),
})

